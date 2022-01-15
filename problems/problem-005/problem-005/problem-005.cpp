// problem-005.cpp
#include <iostream>

#include <libmath/PrimeNumbers.h>


int main() {
	math::sequences::Primes obj_primes;
	std::cout << obj_primes.get_smallest_multiple(20) << std::endl;

	return 0;
}
