// problem-010.cpp
#include<iostream>
#include<string>
#include<vector>
#include"Primes.h"

int main() {
	Primes obj_primes("primes");
	std::cout << obj_primes.get_sum_to(2000000) << std::endl;

    return 0;
}
