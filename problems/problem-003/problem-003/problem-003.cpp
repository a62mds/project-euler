// problem-003.cpp
#include <iostream>

#include <libmath/PrimeNumbers.h>


const math::numbers::natural THE_NUMBER = 600851475143;


int main() {

	math::sequences::Primes primes;
	std::vector<math::numbers::natural> prime_factors = primes.get_prime_factors(THE_NUMBER);

	std::cout << "Largest prime divisor: " << prime_factors.back() << std::endl;

	return 0;
}
