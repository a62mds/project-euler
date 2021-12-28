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
