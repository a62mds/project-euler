#include "doctest.h"

#include"PrimeNumbers.h"


TEST_CASE("Testing function Primes::is_prime") {
	math::sequences::Primes pr;

	CHECK(pr.is_prime(2));
	CHECK(pr.is_prime(611953));

	CHECK(!pr.is_prime(611952));
}

TEST_CASE("Testing function Primes::get_smallest_prime_divisor") {
	math::sequences::Primes pr;

	CHECK(pr.get_smallest_prime_divisor(2) == 2);
	CHECK(pr.get_smallest_prime_divisor(49) == 7);
	CHECK(pr.get_smallest_prime_divisor(611953) == 611953);
}

TEST_CASE("Test function math::Primes::get_prime_factors") {
	math::sequences::Primes primes;

	CHECK(primes.get_prime_factors(2) == std::vector<math::numbers::natural>{2});
	CHECK(primes.get_prime_factors(3) == std::vector<math::numbers::natural>{3});
	CHECK(primes.get_prime_factors(4) == std::vector<math::numbers::natural>{2, 2});
	CHECK(primes.get_prime_factors(2*2*2*2*3*3*3*3*3*5*5*5*7*7*7*7) == std::vector<math::numbers::natural>{2, 2, 2, 2, 3, 3, 3, 3, 3, 5, 5, 5, 7, 7, 7, 7});
}
