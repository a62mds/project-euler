#include "doctest.h"

#include"PrimeNumbers.h"


TEST_CASE("Testing function Primes::is_prime") {
	math::Primes pr;

	CHECK(pr.is_prime(2));
	CHECK(pr.is_prime(611953));

	CHECK(!pr.is_prime(611952));
}

TEST_CASE("Testing function Primes::get_smallest_prime_divisor") {
	math::Primes pr;

	CHECK(pr.get_smallest_prime_divisor(2) == 2);
	CHECK(pr.get_smallest_prime_divisor(49) == 7);
	CHECK(pr.get_smallest_prime_divisor(611953) == 611953);
}
