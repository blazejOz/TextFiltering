#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "UppercaseFilter.h"

TEST(UppercaseFilter, ConvertsLowercaseToUppercase) {
    UppercaseFilter filter;
    std::string input = "hello world";
    std::string expected = "HELLO WORLD";
    EXPECT_EQ(filter.apply(input), expected);
}

TEST(UppercaseFilter, LeavesUppercaseUnchanged) {
    UppercaseFilter filter;
    std::string input = "ALREADY UPPER";
    std::string expected = "ALREADY UPPER";
    EXPECT_EQ(filter.apply(input), expected);
}

TEST(UppercaseFilter, HandlesMixedCased) {
    UppercaseFilter filter;
    std::string input = "MiXeD CaSeD WorDS";
    std::string expected = "MIXED CASED WORDS";
    EXPECT_EQ(filter.apply(input), expected);
}