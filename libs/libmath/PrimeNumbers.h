#ifndef PRIMES_H
#define PRIMES_H

#include <string>
#include <vector>

#include "NaturalNumbers.h"


namespace math {

const size_t DEFAULT_INITIAL_PRIMES_TO_GENERATE = 50000;

/**
 * Class abstracting the sequence of prime numbers
 */
class Primes {
	public:
		Primes(std::string filename="primes", size_t maxnum=DEFAULT_INITIAL_PRIMES_TO_GENERATE);

		/**
		 * Checks the whether input is prime
		 */
		bool is_prime(numbers::natural input);

		numbers::natural operator[](int index);

		/**
		 * Returns the name of the file containing the list of prime numbers
		 */
		std::string get_filename() const { return m_filename; }

		/**
		 * Returns the number of prime numbers that have been calculated
		 */
		int get_size() { return m_primes.size(); }

		/**
		 * Find the smallest prime divisor of an integer
		 */
		numbers::natural get_smallest_prime_divisor(numbers::natural input);

		/**
		 * Returns a vector containing the prime factors (with repetition) of the input, sorted in ascending order
		 */
		std::vector<numbers::natural> get_prime_factors(numbers::natural input);

		/**
		 * Returns a vector containing the values of the exponents of each prime, in ascending order, of the prime
		 * number decomposition of the input
		 */
		std::vector<size_t> get_exponent_vector(numbers::natural input);

		/**
		 * Returns smallest positive integer that is divisible by each of the numbers input, input-1, input-2,..., 3, 2
		 */
		numbers::natural get_smallest_multiple(int input);

		/**
		 * Returns the sum of the prime numbers less than the specified maximum
		 */
		numbers::natural get_sum_to(int max);

		/**
		 * Returns the arithmetic derivative of the input
		 */
		numbers::natural arith_deriv(numbers::natural input);

	private:
		/**
		 * Reads a list of prime numbers from a file whose name is specified as input and returns a vector containing
		 * the prime numbers, sorted in ascending order
		 */
		std::vector<numbers::natural> read_file(std::string filename);

		/**
		 * Generates a file containing the first max prime numbers
		 */
		void gen_file(std::string filename, size_t max);

		/**
		 * Sanity checks on indices and values
		 */
		bool in_index_range(size_t index) { return 0 <= index && index <= m_primes.size(); }
		bool in_prime_range(numbers::natural input) { return 1 <= input && input <= m_primes.back(); }

		std::string m_filename;					// Name of file contiaining list of prime numbers
		std::vector<numbers::natural> m_primes;	// Vector into which is read the list of prime numbers from the file
		size_t m_numPrimes;						// Number of primes to generate and store in the prime file
};

}; // namespace math

#endif
