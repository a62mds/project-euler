// problem-484.cpp
#include<iostream>
#include<string>
#include"Primes.h"

using llint = long long int;

int main() {
	// std::cout << gcd(4,8) << std::endl;
	Primes pr;
	//std::cout << pr.arith_deriv(2) << std::endl;
	long long int gcd{1};
	long long int kmin{2};
	long long int kmax{5000000000000000};
	for (long long int k=kmin; k<=kmax; k++) {
		gcd += pr.get_gcd(k,pr.arith_deriv(k));
	}
	std::cout << gcd << std::endl;

    return 0;
}
