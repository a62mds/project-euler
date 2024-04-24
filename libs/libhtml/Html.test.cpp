#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "Html.h"


TEST_CASE("Test function html::strip_tags") {

    SUBCASE("Test stripping HTML tags from a string") {
        std::string input = "<p>This is a <strong>test</strong> string with <em>HTML</em> tags</p>";
        std::string expected_output = "This is a test string with HTML tags";

        CHECK_EQ(html::strip_tags(input), expected_output);
    }

    SUBCASE("Test stripping HTML tags from an empty string") {
        std::string input = "";
        std::string expected_output = "";

        CHECK_EQ(html::strip_tags(input), expected_output);
    }

    SUBCASE("Test stripping HTML tags from a string with no tags") {
        std::string input = "This string has no HTML tags";
        std::string expected_output = "This string has no HTML tags";

        CHECK_EQ(html::strip_tags(input), expected_output);
    }

    SUBCASE("Test stripping HTML tags from a string with only tags") {
        std::string input = "<strong><em><u>This string has only tags</u></em></strong>";
        std::string expected_output = "This string has only tags";

        CHECK_EQ(html::strip_tags(input), expected_output);
    }

    SUBCASE("Test stripping HTML tags from a string with a single less than sign") {
        std::string input = "3 < 5";
        std::string expected_output = "3 < 5";

        CHECK_EQ(html::strip_tags(input), expected_output);
    }
}
