// problem-007.cpp
#include<iostream>
#include<string>
#include<vector>
#include"Primes.h"

int main() {
	Primes obj_primes("primes");
	std::cout << obj_primes[obj_primes.get_size()] << std::endl;

    return 0;
}
