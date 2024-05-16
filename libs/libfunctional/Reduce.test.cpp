#include "doctest.h"

#include "Reduce.h"


TEST_CASE("Test functional::reduce function") {

    SUBCASE("Empty input vector returns initial value") {
        std::vector<int> input;
        int initial_value = 0;
        std::function<int(int, int)> sum = [](int a, int b) { return a + b; };

        CHECK_EQ(functional::reduce(input, initial_value, sum), initial_value);
    }

    SUBCASE("Reducing sum of integers") {
        std::vector<int> input = {1, 2, 3, 4, 5};
        int initial_value = 0;
        std::function<int(int, int)> sum = [](int a, int b) { return a + b; };
        int expected_sum = 15;

        CHECK_EQ(functional::reduce(input, initial_value, sum), expected_sum);
    }

    SUBCASE("Reducing product of integers") {
        std::vector<int> input = {1, 2, 3, 4, 5};
        int initial_value = 1;
        std::function<int(int, int)> product = [](int a, int b) { return a * b; };
        int expected_product = 120;

        CHECK_EQ(functional::reduce(input, initial_value, product), expected_product);
    }

    SUBCASE("Reducing sum of doubles") {
        std::vector<double> input = {1.5, 2.7, 3.9};
        double initial_value = 0.0;
        std::function<double(double, double)> sum = [](double a, double b) { return a + b; };
        double expected_sum = 8.1;

        CHECK_EQ(functional::reduce(input, initial_value, sum) - expected_sum, doctest::Approx(1e-6));
    }
}
