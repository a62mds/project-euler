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

TEST_CASE("Test function math::is_palindrome") {
    SUBCASE("Test palindromic numbers are properly detected") {
        CHECK(math::is_palindrome(1));
        CHECK(math::is_palindrome(22));
        CHECK(math::is_palindrome(121));
        CHECK(math::is_palindrome(5445));
        CHECK(math::is_palindrome(90009));
        CHECK(math::is_palindrome(87656765678));
    }

    SUBCASE("Test non-palindromic numbers are properly rejected") {
        CHECK(!math::is_palindrome(12));
        CHECK(!math::is_palindrome(987654321));
        CHECK(!math::is_palindrome(123456787956));
    }
}

TEST_CASE("Test function math::get_smallest_n_digit_number") {
    CHECK(math::get_smallest_n_digit_number(1) == 0);
    CHECK(math::get_smallest_n_digit_number(2) == 10);
    CHECK(math::get_smallest_n_digit_number(15) == 100000000000000);
}

TEST_CASE("Test function math::get_largest_n_digit_number") {
    CHECK(math::get_largest_n_digit_number(1) == 9);
    CHECK(math::get_largest_n_digit_number(2) == 99);
    CHECK(math::get_largest_n_digit_number(15) == 999999999999999);
}

TEST_CASE("Test function math::operations::exponentiate") {
    SUBCASE("Test powers of 0") {
        CHECK(math::operations::exponentiate(0, 0) == 1);
        CHECK(math::operations::exponentiate(0, 1) == 0);
        CHECK(math::operations::exponentiate(0, 25) == 0);
    }
    SUBCASE("Test powers of 1") {
        CHECK(math::operations::exponentiate(1, 0) == 1);
        CHECK(math::operations::exponentiate(1, 52) == 1);
    }
    SUBCASE("Test powers of 2") {
        CHECK(math::operations::exponentiate(2, 0) == 1);
        CHECK(math::operations::exponentiate(2, 1) == 2);
        CHECK(math::operations::exponentiate(2, 2) == 4);
        CHECK(math::operations::exponentiate(2, 10) == 1024);
    }
    SUBCASE("Test powers of 5") {
        CHECK(math::operations::exponentiate(5, 0) == 1);
        CHECK(math::operations::exponentiate(5, 1) == 5);
        CHECK(math::operations::exponentiate(5, 2) == 25);
        CHECK(math::operations::exponentiate(5, 5) == 3125);
    }
    SUBCASE("Test powers of 10") {
        CHECK(math::operations::exponentiate(10, 0) == 1);
        CHECK(math::operations::exponentiate(10, 1) == 10);
        CHECK(math::operations::exponentiate(10, 2) == 100);
        CHECK(math::operations::exponentiate(10, 15) == 1000000000000000);
    }
}

TEST_CASE("Test class math::sequences::Natural") {
    SUBCASE("Test first 10 terms") {
        math::sequences::Natural nat;
        std::vector<math::numbers::natural> first_10_terms{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (auto& term : first_10_terms) {
            CHECK(term == nat.next());
        }
    }
}

TEST_CASE("Test class math::sequences::Fibonacci") {
    SUBCASE("Test first 10 terms") {
        math::sequences::Fibonacci fib;
        std::vector<math::numbers::natural> first_10_terms{0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
        for (auto& term : first_10_terms) {
            CHECK(term == fib.next());
        }
    }
}
