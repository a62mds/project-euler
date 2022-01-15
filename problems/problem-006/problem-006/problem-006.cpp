// problem-006.cpp
#include <numeric>
#include <iostream>

#include <libmath/NaturalNumbers.h>


// Use 101 instead of 100 because the convention used in the math library is to include 0, whereas the convention in
// the problem does not include 0
const math::numbers::natural HOW_MANY = 101ull;


int main() {
	math::sequences::Natural natural_numbers;

	std::vector<math::numbers::natural> numbers = natural_numbers.next(HOW_MANY);

	math::numbers::natural sum_of_numbers = std::accumulate(numbers.begin(), numbers.end(), 0ull);
	math::numbers::natural square_of_sum = math::operations::square(sum_of_numbers);

	std::vector<math::numbers::natural> squares = math::operations::square(numbers);
	math::numbers::natural sum_of_squares = std::accumulate(squares.begin(), squares.end(), 0ull);

	math::numbers::natural difference = square_of_sum - sum_of_squares;

	std::cout << "Square of sum of first  " << HOW_MANY - 1 << " natural numbers: " << square_of_sum << std::endl;
	std::cout << "Sum of squares of first " << HOW_MANY - 1 << " natural numbers: " << sum_of_squares << std::endl;
	std::cout << "Difference: " << difference << std::endl;

	return 0;
}
