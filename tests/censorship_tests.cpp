#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "CensorFilter.h"

TEST(CensorFilterTest, ReplacesSingleWordOccurrence) {
    CensorFilter filter({"walk"});
    std::string input = "I like to walk outside.";
    std::string expected = "I like to **** outside.";
    EXPECT_EQ(filter.apply(input), expected);
}

TEST(CensorFilterTest, ReplacesMultipleOccurrencesOfSingleWord) {
    CensorFilter filter({"test"});
    std::string input = "test this test case";
    std::string expected = "**** this **** case";
    EXPECT_EQ(filter.apply(input), expected);
}

TEST(CensorFilterTest, ReplacesMultipleDifferentWords) {
    CensorFilter filter({"red", "blue"});
    std::string input = "red and blue balloons";
    std::string expected = "*** and **** balloons";
    EXPECT_EQ(filter.apply(input), expected);
}

TEST(CensorFilterTest, HandlesNoMatches) {
    CensorFilter filter({"unmatched"});
    std::string input = "no bad words here";
    std::string expected = input;
    EXPECT_EQ(filter.apply(input), expected);
}

TEST(CensorFilterTest, HandlesEmptyInput) {
    CensorFilter filter({"anything"});
    std::string input = "";
    std::string expected = "";
    EXPECT_EQ(filter.apply(input), expected);
}

TEST(CensorFilterTest, OverlappingWordBehavior) {
    CensorFilter filter({"aa"});
    std::string input = "aaaa";
    std::string expected = "****"; // two occurrences of "aa" become 4 asterisks total
    EXPECT_EQ(filter.apply(input), expected);
}


