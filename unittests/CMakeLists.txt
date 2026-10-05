# Unit tests for pclink11 (GoogleTest). Enabled with -DPCLINK11_TESTS=ON.
#
#   test_options - in-process tests of command line parsing (main.cpp compiled
#                  with main renamed, so the parser functions can be called)
#   test_lda     - end-to-end tests: run the link11 executable on the .obj
#                  fixtures in data/ and check the produced .LDA files

find_package(GTest REQUIRED)
include(GoogleTest)

# The linker sources, built as a library with main() renamed out of the way
add_library(pclink11_core STATIC
    ../main.cpp ../process.cpp ../tables.cpp ../util.cpp)
target_compile_definitions(pclink11_core PRIVATE main=pclink11_main)
target_include_directories(pclink11_core PUBLIC .. ${CMAKE_BINARY_DIR})

add_executable(test_options test_options.cpp)
target_link_libraries(test_options pclink11_core GTest::gtest_main)

add_executable(test_lda test_lda.cpp)
target_link_libraries(test_lda GTest::gtest_main)
target_include_directories(test_lda PRIVATE ..)
target_compile_definitions(test_lda PRIVATE
    PCLINK11_EXE="$<TARGET_FILE:link11>"
    TEST_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data")
add_dependencies(test_lda link11)

# GoogleTest 1.17 needs C++17; the linker itself stays C++11
set_target_properties(test_options test_lda PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

gtest_discover_tests(test_options)
gtest_discover_tests(test_lda)
