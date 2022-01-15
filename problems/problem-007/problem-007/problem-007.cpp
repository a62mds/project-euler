// problem-007.cpp
#include <iostream>

#include <libmath/PrimeNumbers.h>


const size_t INDEX = 10001;


int main() {
	math::sequences::Primes prime_numbers;

	math::numbers::natural the_prime = prime_numbers[INDEX];

	std::cout << "The " << INDEX << "th prime number is " << the_prime << std::endl;

	return 0;
}
