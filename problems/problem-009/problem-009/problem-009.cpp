// problem-009.cpp
#include <cmath>
#include <iostream>
#include <sstream>
#include <tuple>

#include <libfunctional/Filter.h>
#include <libmath/NaturalNumbers.h>


const math::numbers::natural SUM = 1000ull;

typedef std::tuple<math::numbers::natural, math::numbers::natural, math::numbers::natural> Triple;

std::string to_string(const Triple& abc) {
	std::stringstream ss;
	ss << "(" << std::get<0>(abc) << ", " << std::get<1>(abc) << ", " << std::get<2>(abc) << ")";
	return ss.str();
}


int main() {

	std::function<bool(const Triple&)> sums_to_SUM = [](const Triple& abc){ return std::get<0>(abc) + std::get<1>(abc) + std::get<2>(abc) == SUM; };

	try {
		std::vector<Triple> pythagorean_triples;
		for (math::numbers::natural a=1; a < SUM - 1; a++) {
			for (math::numbers::natural b=a; b <= SUM - a; b++) {
				math::numbers::natural c = std::sqrt(math::operations::square(a) + math::operations::square(b));
				if (math::is_pythagorean_triple(a, b, c)){
					pythagorean_triples.push_back(Triple{a, b, c});
				}
			}
		}

		auto pythagorean_triples_that_sum_to_SUM = functional::filter(pythagorean_triples, sums_to_SUM);

		if (pythagorean_triples_that_sum_to_SUM.size() > 1) {
			std::cerr << "Multiple answers found:" << std::endl;
			for (auto& pythagorean_triple : pythagorean_triples_that_sum_to_SUM) {
				std::cerr << to_string(pythagorean_triple) << std::endl;
			}
		}
		else if (pythagorean_triples_that_sum_to_SUM.size() == 0) {
			std::cerr << "No answers found" << std::endl;
		}
		else {
			int a = std::get<0>(pythagorean_triples_that_sum_to_SUM[0]);
			int b = std::get<1>(pythagorean_triples_that_sum_to_SUM[0]);
			int c = std::get<2>(pythagorean_triples_that_sum_to_SUM[0]);
			std::cout << "Product of elements of " << to_string(pythagorean_triples_that_sum_to_SUM[0]) << " is " << a * b * c << std::endl;
		}
	}
	catch(std::exception& e) {
		std::cerr << "Caught " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
