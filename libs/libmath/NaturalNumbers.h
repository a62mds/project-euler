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
 * Compute the GCD of the inputs
 */
numbers::natural get_gcd(numbers::natural lhs, numbers::natural rhs);

/**
 * Get all multiples of a number less than a given upper bound
 */
std::vector<numbers::natural> get_multiples_less_than(numbers::natural multiplicand, numbers::natural upper_bound);

}; // namespace math

#endif
