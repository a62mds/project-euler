// problem-006.cpp
#include<iostream>

long long int sum_to(int max) {
	int sum{0};
	for (int ii=1; ii<=max; ii++) sum+=ii;
	return sum;
}

long long int square(int num) { return num*num; }

long long sum_squares_to(int max) {
	int sqsum{0};
	for (int ii=1; ii<=max; ii++) sqsum+=square(ii);
	return sqsum;
}

int main() {
	int max{100};
	std::cout << sum_to(max) << std::endl;
	std::cout << square(sum_to(max)) << std::endl;
	std::cout << sum_squares_to(max) << std::endl;
	std::cout << square(sum_to(max)) - sum_squares_to(max) << std::endl;

    return 0;
}
