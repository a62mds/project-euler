// problem-004.cpp
#include <algorithm>
#include <iostream>

#include <libmath/PrimeNumbers.h>


int main() {
	std::vector<math::numbers::natural> palindromic_products_of_3_digit_numbers;

	math::numbers::natural largest_3_digit_number = math::get_largest_n_digit_number(3);
	math::numbers::natural smallest_3_digit_number = math::get_smallest_n_digit_number(3);
	for (math::numbers::natural left_multiplicand=largest_3_digit_number; left_multiplicand >= smallest_3_digit_number; left_multiplicand--) {
		for (math::numbers::natural right_multiplicand=left_multiplicand; right_multiplicand >= smallest_3_digit_number; right_multiplicand--) {
			math::numbers::natural product = left_multiplicand * right_multiplicand;
			if (math::is_palindrome(product)) {
				palindromic_products_of_3_digit_numbers.push_back(product);
			}
		}
	}

	math::numbers::natural largest_palindromic_product_of_3_digit_numbers = *std::max_element(
		palindromic_products_of_3_digit_numbers.begin(),
		palindromic_products_of_3_digit_numbers.end()
	);

	if (largest_palindromic_product_of_3_digit_numbers > 0) {
		std::cout << "Largest palindrome made from the product of two 3-digit numbers: " << largest_palindromic_product_of_3_digit_numbers << std::endl;
	} else {
		std::cerr << "Failed to find palindrome made from the product of two 3-digit numbers" << std::endl;
	}

	return 0;
}
