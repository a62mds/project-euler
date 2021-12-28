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

}; // namespace math
