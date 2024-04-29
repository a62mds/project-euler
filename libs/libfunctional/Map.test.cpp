#include "doctest.h"

#include <string>

#include "Map.h"


TEST_CASE("Test functional::map function") {

    SUBCASE("Empty input vector returns empty output vector") {
        std::vector<int> input;
        std::function<int(int)> square = [](int x) { return x * x; };

        CHECK(functional::map(input, square).empty());
    }

    SUBCASE("Mapping squares of integers") {
        std::vector<int> input = {1, 2, 3, 4, 5};
        std::function<int(int)> square = [](int x) { return x * x; };
        std::vector<int> expected = {1, 4, 9, 16, 25};

        CHECK_EQ(functional::map(input, square), expected);
    }

    SUBCASE("Mapping doubles to integers") {
        std::vector<double> input = {1.5, 2.7, 3.9};
        std::function<int(double)> to_int = [](double x) { return static_cast<int>(x); };
        std::vector<int> expected = {1, 2, 3};

        CHECK_EQ(functional::map(input, to_int), expected);
    }

    SUBCASE("Mapping string lengths") {
        std::vector<std::string> input = {"apple", "banana", "orange"};
        std::function<size_t(const std::string&)> get_size = [](const std::string& str) { return str.size(); };
        std::vector<size_t> expected = {5, 6, 6};

        CHECK_EQ(functional::map(input, get_size), expected);
    }
}
