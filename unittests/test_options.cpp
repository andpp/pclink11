// test_options.cpp : Command line parsing tests for PCLINK11.
//
// Calls the parser in main.cpp directly and checks the resulting globals.
// Errors go through fatal_error(), which prints to stdout and exits with
// EXIT_FAILURE, so they are tested as death tests with stdout sent to stderr.

#include <gtest/gtest.h>

#include <unistd.h>
#include <cstring>
#include <initializer_list>
#include <vector>

#include "main.h"

// Defined in main.cpp, not declared in main.h
void initialize();
void finalize();
void parse_commandline(int argc, char **argv);
extern bool g_okHelpRequested;
extern bool g_okVersionRequested;

namespace
{

class OptionsTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        initialize();
        g_okHelpRequested = false;
        g_okVersionRequested = false;
        savfilename[0] = 0;
    }
    void TearDown() override
    {
        finalize();
    }

    // Parse a command line; argv[0] is supplied
    static void Parse(std::initializer_list<const char*> args)
    {
        std::vector<std::vector<char>> storage;
        std::vector<char*> argv;
        storage.reserve(args.size() + 1);
        storage.emplace_back(std::vector<char>{'p', 'c', 'l', 'i', 'n', 'k', '1', '1', 0});
        for (const char* a : args)
            storage.emplace_back(std::vector<char>(a, a + strlen(a) + 1));
        for (auto& s : storage)
            argv.push_back(s.data());
        parse_commandline((int)argv.size(), argv.data());
    }

    // For death tests: fatal_error() prints to stdout, death tests match stderr
    static void ParseExpectingError(std::initializer_list<const char*> args)
    {
        fflush(stdout);
        dup2(fileno(stderr), fileno(stdout));
        Parse(args);
    }
};

#define EXPECT_PARSE_ERROR(args, regex) \
    EXPECT_EXIT(ParseExpectingError args, ::testing::ExitedWithCode(EXIT_FAILURE), regex)

// ---- Input files ----

TEST_F(OptionsTest, InputFileIsRecorded)
{
    Parse({"HELLO.OBJ"});
    ASSERT_EQ(SaveStatusCount, 1);
    EXPECT_STREQ(SaveStatusArea[0].filename, "HELLO.OBJ");
}

TEST_F(OptionsTest, SeveralInputFilesKeepOrder)
{
    Parse({"MAIN.OBJ", "SUBS.OBJ"});
    ASSERT_EQ(SaveStatusCount, 2);
    EXPECT_STREQ(SaveStatusArea[0].filename, "MAIN.OBJ");
    EXPECT_STREQ(SaveStatusArea[1].filename, "SUBS.OBJ");
}

TEST_F(OptionsTest, NoInputFileIsAnError)
{
    EXPECT_PARSE_ERROR(({"/LDA"}), "Input file not specified");
}

// ---- /LDA ----

TEST_F(OptionsTest, LdaIsOffByDefault)
{
    Parse({"HELLO.OBJ"});
    EXPECT_FALSE(Globals.FlagLDA);
    EXPECT_FALSE(Globals.FlagBIN);
}

TEST_F(OptionsTest, LdaSetsFlag)
{
    Parse({"HELLO.OBJ", "/LDA"});
    EXPECT_TRUE(Globals.FlagLDA);
    EXPECT_FALSE(Globals.FlagBIN);
}

TEST_F(OptionsTest, LdaWithDashPrefix)
{
    Parse({"HELLO.OBJ", "-LDA"});
    EXPECT_TRUE(Globals.FlagLDA);
}

TEST_F(OptionsTest, LdaBeforeInputFile)
{
    Parse({"/LDA", "HELLO.OBJ"});
    EXPECT_TRUE(Globals.FlagLDA);
    EXPECT_EQ(SaveStatusCount, 1);
}

TEST_F(OptionsTest, LdaWithExecuteKeepsName)
{
    Parse({"HELLO.OBJ", "/LDA", "/EXECUTE:OUT.LDA"});
    EXPECT_TRUE(Globals.FlagLDA);
    EXPECT_STREQ(savfilename, "OUT.LDA");
}

TEST_F(OptionsTest, LdaAndBinAreMutuallyExclusive)
{
    EXPECT_PARSE_ERROR(({"HELLO.OBJ", "/LDA", "/BIN"}), "/BIN and /LDA are mutually exclusive");
}

TEST_F(OptionsTest, BinAndLdaAreMutuallyExclusive)
{
    EXPECT_PARSE_ERROR(({"HELLO.OBJ", "/BIN", "/LDA"}), "/BIN and /LDA are mutually exclusive");
}

// ---- Other output options ----

TEST_F(OptionsTest, BinSetsFlag)
{
    Parse({"HELLO.OBJ", "/BIN"});
    EXPECT_TRUE(Globals.FlagBIN);
    EXPECT_FALSE(Globals.FlagLDA);
}

TEST_F(OptionsTest, ExecuteSetsOutputName)
{
    Parse({"HELLO.OBJ", "/EXECUTE:PROG.SAV"});
    EXPECT_STREQ(savfilename, "PROG.SAV");
}

TEST_F(OptionsTest, MapAndSymbolTable)
{
    Parse({"HELLO.OBJ", "/MAP", "/SYMBOLTABLE"});
    EXPECT_TRUE(Globals.FlagMAP);
    EXPECT_TRUE(Globals.FlagSTB);
}

TEST_F(OptionsTest, ShortSymbolTable)
{
    Parse({"HELLO.OBJ", "/STB"});
    EXPECT_TRUE(Globals.FlagSTB);
}

TEST_F(OptionsTest, WideMap)
{
    Parse({"HELLO.OBJ", "/W"});
    EXPECT_EQ(Globals.NUMCOL, 6);
}

TEST_F(OptionsTest, NoBitmapAndAlphabetize)
{
    Parse({"HELLO.OBJ", "/X", "/A"});
    EXPECT_TRUE(Globals.SWITCH & SW_X);
    EXPECT_TRUE(Globals.SWITCH & SW_A);
}

// ---- Address options ----

TEST_F(OptionsTest, TransferAddress)
{
    Parse({"HELLO.OBJ", "/T:1004"});
    EXPECT_TRUE(Globals.SWITCH & SW_T);
    EXPECT_EQ(Globals.BEGBLK.value, 01004);
}

TEST_F(OptionsTest, TransferAddressNeedsValue)
{
    EXPECT_PARSE_ERROR(({"HELLO.OBJ", "/T"}), "Invalid /T option");
}

TEST_F(OptionsTest, BottomAddress)
{
    Parse({"HELLO.OBJ", "/B:2000"});
    EXPECT_TRUE(Globals.SWITCH & SW_B);
    EXPECT_EQ(Globals.BOTTOM, 02000);
    EXPECT_EQ(Globals.DBOTTM, 02000);
}

TEST_F(OptionsTest, BottomAddressMustBeEven)
{
    EXPECT_PARSE_ERROR(({"HELLO.OBJ", "/B:2001"}), "use even address");
}

TEST_F(OptionsTest, StackAddress)
{
    Parse({"HELLO.OBJ", "/M:776"});
    EXPECT_TRUE(Globals.SWITCH & SW_M);
    EXPECT_EQ(Globals.STKBLK.value, 0776);
}

TEST_F(OptionsTest, StackAddressMustBeEven)
{
    EXPECT_PARSE_ERROR(({"HELLO.OBJ", "/M:777"}), "use even address");
}

TEST_F(OptionsTest, HighAddressMustBeEven)
{
    EXPECT_PARSE_ERROR(({"HELLO.OBJ", "/H:157777"}), "use even address");
}

// ---- Help, version, unknown ----

TEST_F(OptionsTest, HelpNeedsNoInputFile)
{
    Parse({"--help"});
    EXPECT_TRUE(g_okHelpRequested);
}

TEST_F(OptionsTest, VersionNeedsNoInputFile)
{
    Parse({"--version"});
    EXPECT_TRUE(g_okVersionRequested);
}

TEST_F(OptionsTest, UnknownOptionIsAnError)
{
    EXPECT_PARSE_ERROR(({"HELLO.OBJ", "/Z"}), "Unknown command line option 'Z'");
}

}  // namespace
