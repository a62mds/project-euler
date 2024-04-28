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
