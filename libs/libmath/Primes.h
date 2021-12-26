#ifndef PRIMES_H
#define PRIMES_H

#include <string>
#include <vector>


namespace math {

const size_t DEFAULT_INITIAL_PRIMES_TO_GENERATE = 50000;

typedef long long unsigned natural;

class Primes {
	public:
		Primes(std::string filename="primes", size_t maxnum=DEFAULT_INITIAL_PRIMES_TO_GENERATE);

		bool is_prime(natural input);
		bool is_divisible_by(natural lhs, natural rhs) { return lhs%rhs==0; }

		natural operator[](int index);

		// Get filename
		std::string get_filename() const { return m_filename; }

		// Get length of m_primes
		int get_size() { return m_primes.size(); }

		// Returns the smallest prime divisor of input
		natural get_smallest_prime_divisor(natural input);

		// Returns a vector of the prime factors of input sorted in ascending order
		std::vector<natural> get_prime_factors(natural input);

		// Returns a vector containing the values of the exponents of each prime, in
		// ascending order, of the prime number decomposition of the input
		std::vector<size_t> get_exponent_vector(natural input);

		// Returns smallest positive integer that is divisible by each of the
		// numbers input, input-1, input-2, ..., 3, 2
		natural get_smallest_multiple(int input);

		// Returns the sum of all primes less than max
		natural get_sum_to(int max);

		// Returns the GCD of the two inputs
		natural get_gcd(natural lhs, natural rhs);

		// Returns the arithmetic derivative of the input
		natural arith_deriv(natural input);

	private:
		// Reads the list of prime numbers from the file into m_primes
		std::vector<natural> read_file(std::string filename);

		// Generates a file containingthe first max prime numbers
		void gen_file(std::string filename, size_t max);

		// Sanity checks on indices and values
		bool in_index_range(size_t index) { return 0 <= index && index <= m_primes.size(); }
		bool in_prime_range(natural input) { return 1 <= input && input <= m_primes.back(); }

		std::string m_filename;					// Name of file contiaining list of prime numbers
		std::vector<natural> m_primes;	// Vector into which is read the list of prime numbers from the file
		size_t m_numPrimes;						// Number of primes to generate and store in the prime file
};

}; // namespace math

#endif
