#include "NaturalNumbers.h"


namespace math {

bool is_divisible_by(numbers::natural numerator, numbers::natural denominator) {
    return numerator % denominator == 0;
}

numbers::natural get_gcd(numbers::natural lhs, numbers::natural rhs) {
    numbers::natural min{lhs <= rhs ? lhs : rhs};
    for (numbers::natural denom=min; denom >= 1; denom--) {
        if (is_divisible_by(lhs, denom) && is_divisible_by(rhs, denom)) {
            return denom;
        }
    }
    return 1;
}

std::vector<numbers::natural> get_multiples_less_than(numbers::natural multiplicand, numbers::natural upper_bound) {
    if (upper_bound <= multiplicand) {
        return std::vector<numbers::natural>();
    }

    numbers::natural number_of_multiples = upper_bound / multiplicand;
    // If the upper bound is divisible by the multiplicand, the integer division gives one too many for the number of
    // multiples of the multiplicand less than the upper bound. Subtract one if this is the case, and just stick with
    // the division otherwise.
    if (is_divisible_by(upper_bound, multiplicand)) {
        number_of_multiples--;
    }

    std::vector<numbers::natural> multiples;
    multiples.reserve(number_of_multiples);
    for (numbers::natural multiplier=1; multiplier <= number_of_multiples; multiplier++) {
        multiples.push_back(multiplier * multiplicand);
    }

    return multiples;
}

}; // namespace math
