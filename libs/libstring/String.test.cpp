#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "String.h"


TEST_CASE("Test function string::split") {

    SUBCASE("Split string on whitespace") {
        std::string to_split = "This is a normal sentence delimited by whitespace.";

        std::vector<std::string> expected_tokens{
            "This",
            "is",
            "a",
            "normal",
            "sentence",
            "delimited",
            "by",
            "whitespace."
        };

        CHECK_EQ(string::split(to_split, ' '), expected_tokens);
    }

    SUBCASE("Split string on whitespace when there are multiple spaces") {
        std::string to_split = "This string  sometimes has   multiple spaces";

        std::vector<std::string> expected_tokens{
            "This",
            "string",
            "",
            "sometimes",
            "has",
            "",
            "",
            "multiple",
            "spaces"
        };

        CHECK_EQ(string::split(to_split, ' '), expected_tokens);
    }

    SUBCASE("Split string on comma") {
        std::string to_split = "this,is,a,csv,string";

        std::vector<std::string> expected_tokens{
            "this",
            "is",
            "a",
            "csv",
            "string"
        };

        CHECK_EQ(string::split(to_split, ','), expected_tokens);
    }
}

TEST_CASE("Test string::join function") {

    SUBCASE("Empty vector returns empty string") {
        std::vector<std::string> tokens;

        std::string expected = "";

        CHECK_EQ(string::join(tokens, ','), expected);
    }

    SUBCASE("Single element vector returns that element") {
        std::vector<std::string> tokens = {"hello"};

        std::string expected = "hello";

        CHECK_EQ(string::join(tokens, ','), expected);
    }

    SUBCASE("Multiple elements are joined with delimiter") {
        std::vector<std::string> tokens = {"apple", "banana", "orange"};

        std::string expected = "apple,banana,orange";

        CHECK_EQ(string::join(tokens, ','), expected);
    }

    SUBCASE("Delimiter is included between elements") {
        std::vector<std::string> tokens = {"1", "2", "3"};

        std::string expected = "1-2-3";

        CHECK_EQ(string::join(tokens, '-'), expected);
    }

    SUBCASE("Empty strings are included") {
        std::vector<std::string> tokens = {"", "hello", "", "world", ""};

        std::string expected = " hello  world ";

        CHECK_EQ(string::join(tokens, ' '), expected);
    }
}

TEST_CASE("Test string::is_numeric function") {

    SUBCASE("Empty string is not numeric") {
        CHECK_FALSE(string::is_numeric(""));
    }

    SUBCASE("Non-numeric string is not numeric") {
        CHECK_FALSE(string::is_numeric("abc"));
    }

    SUBCASE("Numeric string is numeric") {
        CHECK(string::is_numeric("123"));
    }

    SUBCASE("Alphanumeric string is not numeric") {
        CHECK_FALSE(string::is_numeric("123abc"));
    }

    SUBCASE("String with leading and trailing spaces is not numeric") {
        CHECK_FALSE(string::is_numeric(" 123 "));
    }
}
