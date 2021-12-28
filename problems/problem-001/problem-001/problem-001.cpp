#include <algorithm>
#include <iostream>
#include <numeric>

#include <libmath/NaturalNumbers.h>


const math::numbers::natural UPPER_BOUND = 1000;


int main() {

	std::vector<math::numbers::natural> multiples_of_3 = math::get_multiples_less_than(3, UPPER_BOUND);
	std::vector<math::numbers::natural> multiples_of_5 = math::get_multiples_less_than(5, UPPER_BOUND);

	std::vector<math::numbers::natural> multiples_of_3_or_5;
	multiples_of_3_or_5.reserve(multiples_of_3.size() + multiples_of_5.size());
	std::copy(multiples_of_3.begin(), multiples_of_3.end(), std::back_inserter(multiples_of_3_or_5));
	// Ensure numbers that are multiples of both 3 and 5 are not counted twice
	std::copy_if(multiples_of_5.begin(), multiples_of_5.end(), std::back_inserter(multiples_of_3_or_5), [](math::numbers::natural n) { return !math::is_divisible_by(n, 3); });

	math::numbers::natural sum = std::accumulate(multiples_of_3_or_5.begin(), multiples_of_3_or_5.end(), 0ull);
	std::cout << "Sum = " << sum << std::endl;

	return 0;
}
