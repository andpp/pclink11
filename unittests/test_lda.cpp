// test_lda.cpp : End-to-end tests of PCLINK11 /LDA (absolute loader) output.
//
// Each test copies a fixture .obj from data/ (sources: data/*.mac) into a fresh
// temporary directory, runs the linker there, and parses the result.
// The .SAV image of the same object serves as an independent reference: every
// byte loaded by the .LDA must equal the .SAV byte at that address, and the
// .LDA transfer address must equal the .SAV start address (word at 040).

#include <gtest/gtest.h>

#include <sys/wait.h>
#include <cstdint>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

namespace fs = std::filesystem;

namespace
{

struct LdaBlock
{
    uint16_t addr;
    std::vector<uint8_t> data;
};

struct LdaFile
{
    std::vector<LdaBlock> blocks;  // data blocks, in file order
    uint16_t transfer = 0;         // load address of the final (empty) block
};

std::vector<uint8_t> ReadFile(const fs::path& path)
{
    std::ifstream f(path, std::ios::binary);
    return std::vector<uint8_t>(std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>());
}

uint16_t Word(const std::vector<uint8_t>& b, size_t at)
{
    return (uint16_t)(b[at] | (b[at + 1] << 8));
}

// Parse and validate absolute loader format: each block is 001 000, byte count
// (header + data), load address, data, checksum byte making the block sum zero.
// The first block with no data holds the transfer address and ends the file.
::testing::AssertionResult ParseLda(const std::vector<uint8_t>& b, LdaFile* out)
{
    size_t pos = 0;
    for (;;)
    {
        if (pos + 6 > b.size())
            return ::testing::AssertionFailure() << "truncated block header at offset " << pos;
        if (b[pos] != 1 || b[pos + 1] != 0)
            return ::testing::AssertionFailure() << "block at offset " << pos << " does not start with 001 000";
        uint16_t count = Word(b, pos + 2);
        uint16_t addr = Word(b, pos + 4);
        if (count < 6)
            return ::testing::AssertionFailure() << "byte count " << count << " < 6 at offset " << pos;
        if (pos + count + 1 > b.size())
            return ::testing::AssertionFailure() << "block at offset " << pos << " runs past end of file";
        uint8_t sum = 0;
        for (size_t i = pos; i <= pos + count; i++)
            sum += b[i];
        if (sum != 0)
            return ::testing::AssertionFailure() << "bad checksum in block at offset " << pos;
        if (count == 6)
        {
            out->transfer = addr;
            if (pos + 7 != b.size())
                return ::testing::AssertionFailure() << (b.size() - pos - 7) << " bytes after the transfer block";
            return ::testing::AssertionSuccess();
        }
        out->blocks.push_back({addr, std::vector<uint8_t>(b.begin() + pos + 6, b.begin() + pos + count)});
        pos += count + 1;
    }
}

class LdaTest : public ::testing::Test
{
protected:
    fs::path dir;

    void SetUp() override
    {
        std::string tmpl = (fs::temp_directory_path() / "pclink11_lda_XXXXXX").string();
        ASSERT_NE(mkdtemp(tmpl.data()), nullptr);
        dir = tmpl;
    }
    void TearDown() override
    {
        if (!HasFailure())
            fs::remove_all(dir);
        else
            std::cerr << "test files kept in " << dir << "\n";
    }

    // Copy data/<name>.obj into the work dir
    void UseFixture(const std::string& name)
    {
        fs::copy_file(fs::path(TEST_DATA_DIR) / (name + ".obj"), dir / (name + ".obj"));
    }

    // Run the linker in the work dir; returns its exit code, output in link.log
    int Link(const std::string& args)
    {
        std::string cmd = "cd '" + dir.string() + "' && '" PCLINK11_EXE "' " + args + " > link.log 2>&1";
        int rc = std::system(cmd.c_str());
        return WIFEXITED(rc) ? WEXITSTATUS(rc) : -1;
    }

    std::string LinkLog()
    {
        auto b = ReadFile(dir / "link.log");
        return std::string(b.begin(), b.end());
    }

    // True if a file with exactly this name (case included) exists in the work dir
    bool HasFile(const std::string& name)
    {
        for (const auto& e : fs::directory_iterator(dir))
            if (e.path().filename() == name)
                return true;
        return false;
    }

    // Link <name>.obj with /LDA into <name>.LDA and parse it
    void LinkLda(const std::string& name, LdaFile* lda)
    {
        UseFixture(name);
        ASSERT_EQ(Link(name + ".obj /LDA"), 0) << LinkLog();
        ASSERT_TRUE(HasFile(name + ".LDA")) << LinkLog();
        ASSERT_TRUE(ParseLda(ReadFile(dir / (name + ".LDA")), lda));
    }

    // Link <name>.obj (already copied) into <name>.SAV and return the image
    std::vector<uint8_t> LinkSav(const std::string& name)
    {
        EXPECT_EQ(Link(name + ".obj"), 0) << LinkLog();
        return ReadFile(dir / (name + ".SAV"));
    }
};

// ---- Properties every fixture must satisfy ----

class LdaFixtureTest : public LdaTest, public ::testing::WithParamInterface<const char*> {};

TEST_P(LdaFixtureTest, MatchesSavImage)
{
    const std::string name = GetParam();
    LdaFile lda;
    ASSERT_NO_FATAL_FAILURE(LinkLda(name, &lda));
    std::vector<uint8_t> sav = LinkSav(name);
    ASSERT_GE(sav.size(), 512u);

    EXPECT_EQ(lda.transfer, Word(sav, 040)) << "transfer address differs from .SAV start address";
    for (const LdaBlock& blk : lda.blocks)
    {
        ASSERT_LE(blk.addr + blk.data.size(), sav.size()) << "block at " << std::oct << blk.addr;
        for (size_t i = 0; i < blk.data.size(); i++)
            ASSERT_EQ(blk.data[i], sav[blk.addr + i]) << "byte at " << std::oct << (blk.addr + i);
    }
}

TEST_P(LdaFixtureTest, BlocksAreOrderedBoundedAndDisjoint)
{
    LdaFile lda;
    ASSERT_NO_FATAL_FAILURE(LinkLda(GetParam(), &lda));
    ASSERT_FALSE(lda.blocks.empty());
    for (size_t i = 0; i < lda.blocks.size(); i++)
    {
        EXPECT_FALSE(lda.blocks[i].data.empty());
        EXPECT_LE(lda.blocks[i].data.size(), 0400u);
        if (i > 0)
            EXPECT_GE(lda.blocks[i].addr, lda.blocks[i - 1].addr + lda.blocks[i - 1].data.size());
    }
}

INSTANTIATE_TEST_SUITE_P(Fixtures, LdaFixtureTest,
                         ::testing::Values("hello", "multi", "nostart", "big", "rel"));

// ---- Specific layouts ----

TEST_F(LdaTest, HelloIsOneBlockStartingAt1000)
{
    LdaFile lda;
    ASSERT_NO_FATAL_FAILURE(LinkLda("hello", &lda));
    ASSERT_EQ(lda.blocks.size(), 1u);
    EXPECT_EQ(lda.blocks[0].addr, 01000);
    EXPECT_EQ(lda.blocks[0].data.size(), 062u);  // code + "Hello, world!" CR LF NUL
    EXPECT_EQ(lda.transfer, 01000);
}

TEST_F(LdaTest, GapsAreNotLoaded)
{
    LdaFile lda;
    ASSERT_NO_FATAL_FAILURE(LinkLda("multi", &lda));
    ASSERT_EQ(lda.blocks.size(), 2u);

    // vector at 4: .WORD TRAP4,340
    EXPECT_EQ(lda.blocks[0].addr, 4);
    ASSERT_EQ(lda.blocks[0].data.size(), 4u);
    EXPECT_EQ(Word(lda.blocks[0].data, 0), 01632);  // TRAP4
    EXPECT_EQ(Word(lda.blocks[0].data, 2), 0340);

    // code at START; nothing for the .BLKW area 1000-1617
    EXPECT_EQ(lda.blocks[1].addr, 01620);
    EXPECT_EQ(lda.blocks[1].data.size(), 014u);
}

TEST_F(LdaTest, TransferAddressIsEntryNotLoadBase)
{
    LdaFile lda;
    ASSERT_NO_FATAL_FAILURE(LinkLda("multi", &lda));
    EXPECT_EQ(lda.transfer, 01620);
}

TEST_F(LdaTest, NoStartAddressGivesOddTransfer)
{
    LdaFile lda;
    ASSERT_NO_FATAL_FAILURE(LinkLda("nostart", &lda));
    EXPECT_EQ(lda.transfer, 1);  // odd: the absolute loader halts instead of starting
    ASSERT_EQ(lda.blocks.size(), 1u);
    EXPECT_EQ(lda.blocks[0].addr, 01000);
    EXPECT_EQ(Word(lda.blocks[0].data, 0), 0);  // HALT
}

TEST_F(LdaTest, LongRunIsSplitIntoBlocks)
{
    LdaFile lda;
    ASSERT_NO_FATAL_FAILURE(LinkLda("big", &lda));
    ASSERT_EQ(lda.blocks.size(), 2u);
    EXPECT_EQ(lda.blocks[0].addr, 01000);
    EXPECT_EQ(lda.blocks[0].data.size(), 0400u);
    EXPECT_EQ(lda.blocks[1].addr, 01400);
    EXPECT_EQ(lda.blocks[1].data.size(), 0200u);
    EXPECT_EQ(Word(lda.blocks[0].data, 2), 1);      // first .WORD N at 1002
    EXPECT_EQ(Word(lda.blocks[1].data, 0176), 0277); // last .WORD N at 1576
    EXPECT_EQ(lda.transfer, 01000);
}

TEST_F(LdaTest, RelocatableSectionsAreRelocated)
{
    LdaFile lda;
    ASSERT_NO_FATAL_FAILURE(LinkLda("rel", &lda));
    ASSERT_EQ(lda.blocks.size(), 1u);
    EXPECT_EQ(lda.blocks[0].addr, 01000);
    EXPECT_EQ(Word(lda.blocks[0].data, 0), 012701);  // MOV #MSG,R1
    EXPECT_EQ(Word(lda.blocks[0].data, 2), 01006);   // MSG relocated after CODE
    EXPECT_EQ(lda.transfer, 01000);
}

// ---- Output file naming and option interaction ----

TEST_F(LdaTest, ExecuteOptionNamesOutput)
{
    UseFixture("hello");
    ASSERT_EQ(Link("hello.obj /LDA /EXECUTE:out.lda"), 0) << LinkLog();
    EXPECT_TRUE(HasFile("out.lda"));
    EXPECT_FALSE(HasFile("hello.LDA"));
    LdaFile lda;
    EXPECT_TRUE(ParseLda(ReadFile(dir / "out.lda"), &lda));
}

TEST_F(LdaTest, LdaWithBinFailsAndWritesNothing)
{
    UseFixture("hello");
    EXPECT_EQ(Link("hello.obj /LDA /BIN"), EXIT_FAILURE);
    EXPECT_NE(LinkLog().find("mutually exclusive"), std::string::npos) << LinkLog();
    EXPECT_FALSE(HasFile("hello.LDA"));
    EXPECT_FALSE(HasFile("hello.bin"));
}

TEST_F(LdaTest, BinOutputIsUnchanged)
{
    UseFixture("hello");
    ASSERT_EQ(Link("hello.obj /BIN"), 0) << LinkLog();
    std::vector<uint8_t> bin = ReadFile(dir / "hello.bin");
    ASSERT_GE(bin.size(), 4u);
    EXPECT_EQ(Word(bin, 0), 01000);           // load address
    EXPECT_EQ(Word(bin, 2), 062);             // byte count
    EXPECT_EQ(bin.size(), 4u + 062u);
}

// Known bug, independent of /LDA: /T:addr fails with "ERR31: Transfer address
// undefined or in overlay" (also for .SAV output). Enable once /T is fixed.
TEST_F(LdaTest, DISABLED_TransferOptionOverridesEnd)
{
    UseFixture("hello");
    ASSERT_EQ(Link("hello.obj /LDA /T:1004"), 0) << LinkLog();
    LdaFile lda;
    ASSERT_TRUE(ParseLda(ReadFile(dir / "hello.LDA"), &lda));
    EXPECT_EQ(lda.transfer, 01004);
}

}  // namespace
