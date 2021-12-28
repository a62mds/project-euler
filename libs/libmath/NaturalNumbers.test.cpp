#include "doctest.h"

#include "NaturalNumbers.h"


TEST_CASE("Test function math::is_divisble_by") {

    CHECK(math::is_divisible_by(4, 2));
    CHECK(math::is_divisible_by(2453422, 2));

    CHECK(!math::is_divisible_by(5, 2));
}

TEST_CASE("Test function math::get_gcd") {

    CHECK(math::get_gcd(4, 2) == 2);
    CHECK(math::get_gcd(9, 3) == 3);
    CHECK(math::get_gcd(2453422, 2) == 2);

    CHECK(math::get_gcd(5, 2) == 1);
}

TEST_CASE("Test function math::get_multiples_less_than") {

    CHECK(math::get_multiples_less_than(3, 2) == std::vector<math::numbers::natural>());

    std::vector<math::numbers::natural> multiples_of_2_less_than_3 = math::get_multiples_less_than(2, 3);
    CHECK(multiples_of_2_less_than_3 == std::vector<math::numbers::natural>{2});

    std::vector<math::numbers::natural> multiples_of_3_less_than_12 = math::get_multiples_less_than(3, 12);
    CHECK(multiples_of_3_less_than_12 == std::vector<math::numbers::natural>{3, 6, 9});

    std::vector<math::numbers::natural> multiples_of_1_less_than_100 = math::get_multiples_less_than(1, 100);
    CHECK(multiples_of_1_less_than_100.size() == 99);
    CHECK(multiples_of_1_less_than_100.front() == 1);
    CHECK(multiples_of_1_less_than_100.back() == 99);
}