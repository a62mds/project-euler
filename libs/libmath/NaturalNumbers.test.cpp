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

TEST_CASE("Test function math::is_pythagorean_triple") {
    SUBCASE("Test Pythagorean triples are properly detected") {
        CHECK(math::is_pythagorean_triple(3, 4, 5));
        CHECK(math::is_pythagorean_triple(5, 12, 13));
        CHECK(math::is_pythagorean_triple(7, 24, 25));
        CHECK(math::is_pythagorean_triple(33, 56, 65));
        CHECK(math::is_pythagorean_triple(105, 208, 233));
        CHECK(math::is_pythagorean_triple(120, 209, 241));
    }

    SUBCASE("Test non-Pythagorean triples are properly rejected") {
        CHECK(!math::is_pythagorean_triple(1, 2, 3));
        CHECK(!math::is_pythagorean_triple(1, 1, 1));
        CHECK(!math::is_pythagorean_triple(6, 12, 13));
        CHECK(!math::is_pythagorean_triple(60, 222, 229));
        CHECK(!math::is_pythagorean_triple(120, 209, 240));
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

TEST_CASE("Test function math::get_divisors") {

    SUBCASE("Test trying to get divisors of 0 raises invalid_argument") {
        CHECK_THROWS_AS(math::get_divisors(0), std::invalid_argument);
    }

    SUBCASE("Test only divisor of 1 is 1") {
        std::unordered_set<math::numbers::natural> expected = {1ull};

        CHECK_EQ(math::get_divisors(1ull), expected);
    }

    SUBCASE("Test divisors of 2 are 1 and 2") {
        std::unordered_set<math::numbers::natural> expected = {1ull, 2ull};

        CHECK_EQ(math::get_divisors(2ull), expected);
    }

    SUBCASE("Test divisors of 20 are 1, 2, 4, 5, 10, and 20") {
        std::unordered_set<math::numbers::natural> expected = {
            1ull,
            2ull,
            4ull,
            5ull,
            10ull,
            20ull
        };

        CHECK_EQ(math::get_divisors(20ull), expected);
    }

    SUBCASE("Test divisors of 51 are 1, 3, 17, and 51") {
        std::unordered_set<math::numbers::natural> expected = {
            1ull,
            3ull,
            17ull,
            51ull
        };

        CHECK_EQ(math::get_divisors(51ull), expected);
    }

    SUBCASE("Test divisors of 19081 are 1 and 19081") {
        std::unordered_set<math::numbers::natural> expected = {1ull, 19081ull};

        CHECK_EQ(math::get_divisors(19081ull), expected);
    }
}

TEST_CASE("Test scalar function math::operations::exponentiate") {
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

TEST_CASE("Test vector function math::operations::exponentiate") {
    SUBCASE("Test 0 exponent") {
        std::vector<math::numbers::natural> input{0, 1, 5, 19, 56, 675, 98743, 238092438, 2653765243756, 762347862348726};
        std::vector<math::numbers::natural> expected_output{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

        std::vector<math::numbers::natural> output = math::operations::exponentiate(input, 0);

        CHECK(output == expected_output);
    }

    SUBCASE("Test 1 exponent") {
        std::vector<math::numbers::natural> input{0, 1, 5, 19, 56, 675, 98743, 238092438, 2653765243756, 762347862348726};
        std::vector<math::numbers::natural>& expected_output = input;

        std::vector<math::numbers::natural> output = math::operations::exponentiate(input, 1);

        CHECK(output == expected_output);
    }

    SUBCASE("Test 2 exponent") {
        std::vector<math::numbers::natural> input{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::vector<math::numbers::natural> expected_output{0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

        std::vector<math::numbers::natural> output = math::operations::exponentiate(input, 2);

        CHECK(output == expected_output);
    }
}

TEST_CASE("Test class math::sequences::Natural") {
    std::vector<math::numbers::natural> first_10_terms{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<math::numbers::natural> second_10_terms{10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    SUBCASE("Test next() for first 10 terms") {
        math::sequences::Natural nat;
        for (auto& term : first_10_terms) {
            CHECK(term == nat.next());
        }
    }

    SUBCASE("Test next(10) and next() for first 11 terms") {
        math::sequences::Natural nat;
        CHECK(first_10_terms == nat.next(10));

        CHECK(10 == nat.next());
    }

    SUBCASE("Test next(10) and next(10) for second 10 terms") {
        math::sequences::Natural nat;
        nat.next(10);       // Ignore first 10 terms
        CHECK(second_10_terms == nat.next(10));
    }
}

TEST_CASE("Test class math::sequences::Fibonacci") {
    std::vector<math::numbers::natural> first_10_terms{0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    std::vector<math::numbers::natural> second_10_terms{55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181};

    SUBCASE("Test next() for first 10 terms") {
        math::sequences::Fibonacci fib;
        for (auto& term : first_10_terms) {
            CHECK(term == fib.next());
        }
    }

    SUBCASE("Test next(10) and next() for first 11 terms") {
        math::sequences::Fibonacci fib;
        CHECK(first_10_terms == fib.next(10));

        CHECK(55 == fib.next());
    }

    SUBCASE("Test next(10) and next(10) for second 10 terms") {
        math::sequences::Fibonacci fib;
        fib.next(10);       // Ignore first 10 terms
        CHECK(second_10_terms == fib.next(10));
    }
}

TEST_CASE("Test class math::sequences::TriangleNumbers") {
    std::vector<math::numbers::natural> first_10_terms = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55};
    std::vector<math::numbers::natural> second_10_terms = {66, 78, 91, 105, 120, 136, 153, 171, 190, 210};

    SUBCASE("Test next() for first 10 terms") {
        math::sequences::TriangleNumbers t;
        for (auto& term : first_10_terms) {
            CHECK_EQ(term, t.next());
        }
    }

    SUBCASE("Test next(10) and next() for first 11 terms") {
        math::sequences::TriangleNumbers t;
        CHECK_EQ(first_10_terms, t.next(10));

        CHECK_EQ(second_10_terms[0], t.next());
    }

    SUBCASE("Test next(10) and next(10) for second 10 terms") {
        math::sequences::TriangleNumbers t;
        t.next(10);       // Ignore first 10 terms
        CHECK_EQ(second_10_terms, t.next(10));
    }
}
