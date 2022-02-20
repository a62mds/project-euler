// problem-010.cpp
#include <iostream>

#include <libmath/PrimeNumbers.h>


int UPPER_BOUND = 2000000;


int main() {

	std::cout << math::sequences::Primes().get_sum_to(UPPER_BOUND) << std::endl;

	return 0;
}
