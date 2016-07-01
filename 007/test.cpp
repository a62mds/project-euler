#include<iostream>
#include<vector>
#include"Primes.h"

void print_vector(std::vector<int> input) {
	for (std::vector<int>::iterator it=input.begin(); it!=input.end(); ++it)
		std::cout << *it << std::endl;
}

int main() {
	Primes obj_primes;

	// bool Primes::is_prime(int input)
	// Seems to be working
	//std::cout << obj_primes.is_prime(53) << std::endl;

	// int Primes::get_smallest_prime_divisor(int input)
	// Seems to be working
	//std::cout << obj_primes.get_smallest_prime_divisor(53) << std::endl;

	// std::vector<int> Primes::get_prime_factors(int input)
	// Seems to be working
	//std::vector<int> factors = obj_primes.get_prime_factors(19);
	//print_vector(factors);
	
	// Seems to be working
	//std::vector<int> tst = obj_primes.get_exponent_vector(19);
	//print_vector(tst);
	
	std::cout << obj_primes.get_smallest_multiple(10) << std::endl;
}
