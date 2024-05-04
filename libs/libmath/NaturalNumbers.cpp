#include "NaturalNumbers.h"

#include <algorithm>


namespace math {

bool is_divisible_by(numbers::natural numerator, numbers::natural denominator) {
    return numerator % denominator == 0;
}

bool is_palindrome(numbers::natural number) {
    numbers::natural original_number = number;
    numbers::natural reversed_number = 0;
    while (number != 0) {
        reversed_number = (reversed_number * 10) + number % 10;
        number /= 10;
    }
    return reversed_number == original_number;
}

bool is_pythagorean_triple(numbers::natural a, numbers::natural b, numbers::natural c) {
    return operations::square(c) == operations::square(a) + operations::square(b);
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

numbers::natural get_smallest_n_digit_number(size_t num_digits) {
    return num_digits > 1 ? operations::exponentiate(10, num_digits - 1) : 0;
}

numbers::natural get_largest_n_digit_number(size_t num_digits) {
    return operations::exponentiate(10, num_digits) - 1;
}

std::unordered_set<numbers::natural> get_divisors(numbers::natural dividend) {
    if (dividend == 0ull) {
        throw std::invalid_argument("Everything divides 0");
    }

    std::unordered_set<numbers::natural> divisors;

    divisors.insert(1ull);
    if (dividend == 1ull) {
        return divisors;
    }

    for (numbers::natural candidate=2ull; candidate * candidate <= dividend; ++candidate) {
        if (dividend % candidate == 0) {
            divisors.insert(candidate);
            divisors.insert(dividend / candidate);
        }
    }

    divisors.insert(dividend);

    return divisors;
}

numbers::natural operations::exponentiate(numbers::natural base, size_t exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (base == 0 || base == 1) {
        return base;
    }

    numbers::natural result = 1;
    for (size_t current_exponent=1; current_exponent <= exponent; current_exponent++) {
        result *= base;
    }
    return result;
}

std::vector<numbers::natural> operations::exponentiate(const std::vector<numbers::natural>& bases, size_t exponent) {
    std::vector<numbers::natural> results;
    results.resize(bases.size());

    std::transform(
        bases.begin(),
        bases.end(),
        results.begin(),
        [&exponent](const numbers::natural& base) { return exponentiate(base, exponent); }
    );

    return results;
}

numbers::natural operations::square(numbers::natural number) {
    return exponentiate(number, 2);
}

std::vector<numbers::natural> operations::square(const std::vector<numbers::natural>& numbers) {
    return exponentiate(numbers, 2);
}

std::vector<numbers::natural> sequences::Sequence::next(size_t how_many) {
    std::vector<numbers::natural> terms;
    terms.reserve(how_many);

    for (size_t index=0; index < how_many; index++) {
        terms.push_back(next());
    }

    return terms;
}

numbers::natural sequences::Natural::next() {
    return _next_value++;
}

numbers::natural sequences::Fibonacci::next() {
    numbers::natural current_value = _current_value;
    _current_value = _next_value;
    _next_value += current_value;

    return current_value;
}

sequences::TriangleNumbers::TriangleNumbers() : Sequence(0ull) {
    _natural_numbers.next();
}

numbers::natural sequences::TriangleNumbers::next() {
    _next_value += _natural_numbers.next();

    return _next_value;
}

}; // namespace math
