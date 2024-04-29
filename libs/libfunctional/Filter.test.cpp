#include "doctest.h"

#include <string>

#include "Filter.h"


TEST_CASE("Test function functional::filter") {

    SUBCASE("Test filtering even numbers from vector of ints") {
        std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        std::vector<int> even_numbers{2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
        std::function<bool(const int&)> is_even = [](const int& number){ return number % 2 == 0; };

        CHECK_EQ(functional::filter(numbers, is_even), even_numbers);
    }

    SUBCASE("Test filtering nonempty strings from vector of strings") {
        std::vector<std::string> strings{"s", "t", "rin", "gs", "", "are", "", "f", "u", "n!"};
        std::vector<std::string> nonempty_strings{"s", "t", "rin", "gs", "are", "f", "u", "n!"};
        std::function<bool(const std::string&)> is_nonempty = [](const std::string& string){ return !string.empty(); };

        CHECK_EQ(functional::filter(strings, is_nonempty), nonempty_strings);
    }

}
