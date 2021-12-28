#include <iostream>

#include <libmath/NaturalNumbers.h>


const math::numbers::natural UPPER_BOUND = 4000000ull;


int main() {

	math::sequences::Fibonacci fib;

	math::numbers::natural term = fib.next();
	math::numbers::natural sum = term;
	while (term < UPPER_BOUND) {
		term = fib.next();
		if (math::is_divisible_by(term, 2)) {
			sum += term;
		}
	}

	std::cout << "Sum = " << sum << std::endl;

	return 0;
}
