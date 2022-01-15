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

namespace operations {
    numbers::natural exponentiate(numbers::natural base, size_t exponent);
    std::vector<numbers::natural> exponentiate(const std::vector<numbers::natural>& bases, size_t exponent);

    numbers::natural square(numbers::natural number);
    std::vector<numbers::natural> square(const std::vector<numbers::natural>& numbers);
}; // namesapce operations

namespace sequences {
    /**
     * Abstract base class for sequence classes
     */
    class Sequence {
        public:
            Sequence(numbers::natural initial_value=0) : _next_value(initial_value) {}

            /**
             * Get the next term in the sequence.
             * 
             * This must be implemented by concrete `Sequence` classes
             */
            virtual numbers::natural next() = 0;

            /**
             * Get the next `how_many` terms in the sequence
             */
            std::vector<numbers::natural> next(size_t how_many);
        protected:
            numbers::natural _next_value;
    };

    /**
     * Generate the sequence of natural numbers
     */
    class Natural : public Sequence {
        public:
            Natural() {}

            /**
             * Get the next term in the sequence.
             */
            numbers::natural next();

            /**
             * Get the next `how_many` terms in the sequence
             */
            using Sequence::next;
    };

    /**
     * Generate the Fibonacci sequence
     */
    class Fibonacci : public Sequence {
        public:
            Fibonacci() : Sequence(1ull), _current_value(0ull) {}

            /**
             * Get the next term in the sequence.
             */
            numbers::natural next();

            /**
             * Get the next `how_many` terms in the sequence
             */
            using Sequence::next;
        private:
            numbers::natural _current_value;
    };
}; // namespace sequences

}; // namespace math

#endif
