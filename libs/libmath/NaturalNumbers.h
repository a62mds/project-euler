#ifndef NATURAL_NUMBERS_H
#define NATURAL_NUMBERS_H

#include <vector>


namespace math {

namespace numbers {
    typedef long long unsigned natural;
}; // namespace numbers

/**
 * Check if the numerator is divisible by the denominator
 */
bool is_divisible_by(numbers::natural numerator, numbers::natural denominator);

/**
 * Check if the number is a palendromic number
 */
bool is_palindrome(numbers::natural number);

/**
 * Compute the GCD of the inputs
 */
numbers::natural get_gcd(numbers::natural lhs, numbers::natural rhs);

/**
 * Get all multiples of a number less than a given upper bound
 */
std::vector<numbers::natural> get_multiples_less_than(numbers::natural multiplicand, numbers::natural upper_bound);

/**
 * Get the smallest n-digit number
 */
numbers::natural get_smallest_n_digit_number(size_t num_digits);

/**
 * Get the largest n-digit number
 */
numbers::natural get_largest_n_digit_number(size_t num_digits);

namespace sequences {
    /**
     * Generate the Fibonacci sequence
     */
    class Fibonacci {
        public:
            Fibonacci() : _next_value(1ull), _current_value(0ull) {}

            /**
             * Get the next term in the sequence
             */
            numbers::natural next();
        private:
            numbers::natural _next_value;
            numbers::natural _current_value;
    };
}; // namespace sequences

}; // namespace math

#endif
