#include<iostream>
#include<cassert>
#include<chrono>

#include"Primes.h"

using llint = long long int;

void print_pass_fail(bool);

bool test_is_prime(Primes, llint, bool);
bool test_is_divisible_by(Primes, llint, llint, bool);
bool test_get_smallest_prime_divisor(Primes, llint, llint);
bool test_get_prime_factors(Primes, llint, std::vector<llint>);
bool test_get_exponent_vector(Primes, llint, std::vector<int>);
bool test_get_smallest_multiple(Primes, llint, llint);
bool test_get_gcd(Primes, llint, llint);
bool test_arith_deriv(Primes, llint, llint);

int main() {

	auto t0 = std::chrono::high_resolution_clock::now();

	Primes pr;

	std::cout << "Testing function Primes::is_prime" << std::endl;
	print_pass_fail(test_is_prime(pr, 2, true));
	print_pass_fail(test_is_prime(pr, 1300979, true));
	print_pass_fail(test_is_prime(pr, 2453422, false));

	std::cout << "Testing function Primes::is_divisble_by" << std::endl;
	print_pass_fail(test_is_divisible_by(pr, 4, 2, true));
	print_pass_fail(test_is_divisible_by(pr, 5, 2, false));
	print_pass_fail(test_is_divisible_by(pr, 2453422, 2, true));

	std::cout << "Testing function Primes::get_smallest_prime_divisor" << std::endl;
	print_pass_fail(test_get_smallest_prime_divisor(pr, 2, 2));
	print_pass_fail(test_get_smallest_prime_divisor(pr, 49, 7));
	print_pass_fail(test_get_smallest_prime_divisor(pr, 1300979, 1300979));

	auto t1 = std::chrono::high_resolution_clock::now();
	std::cout << "Tests completed in " 
						<< std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count() 
						<< " ms"
						<< std::endl;
}

void print_pass_fail(bool test) {
	if (test) { std::cout << "Test passed" << std::endl; }
	else {std::cout << "Test failed***" << std::endl; }
}

bool test_is_prime(Primes pr, llint input, bool is_prime) {
	return pr.is_prime(input) == is_prime;
}

bool test_is_divisible_by(Primes pr, llint num, llint denom, bool is_divisible_by) {
	return pr.is_divisible_by(num, denom) == is_divisible_by;
}

bool test_get_smallest_prime_divisor(Primes pr, llint input, llint soln) {
	return pr.get_smallest_prime_divisor(input) == soln;
}
