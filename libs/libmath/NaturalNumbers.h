#ifndef NATURAL_NUMBERS_H
#define NATURAL_NUMBERS_H


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

}; // namespace math

#endif
