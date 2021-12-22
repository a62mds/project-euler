#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include"Primes.h"


TEST_CASE("Testing function Primes::is_prime") {
	Primes pr;

	CHECK(pr.is_prime(2));
	CHECK(pr.is_prime(1300979));

	CHECK(!pr.is_prime(2453422));
}

TEST_CASE("Testing function Primes::is_divisble_by") {
	Primes pr;

	CHECK(pr.is_divisible_by(4, 2));
	CHECK(pr.is_divisible_by(2453422, 2));
	
	CHECK(!pr.is_divisible_by(5, 2));
}

TEST_CASE("Testing function Primes::get_smallest_prime_divisor") {
	Primes pr;

	CHECK(pr.get_smallest_prime_divisor(2) == 2);
	CHECK(pr.get_smallest_prime_divisor(49) == 7);
	CHECK(pr.get_smallest_prime_divisor(1300979) == 1300979);
}
