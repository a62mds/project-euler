#ifndef PRIMES_H
#define PRIMES_H

#include<algorithm>	// for std::count
#include<cmath>			// for pow
#include<fstream>		// used to read the file containing prime numbers
#include<ios>				// exceptions for file io
#include<sstream>		// used to help read file
#include<stdexcept>
#include<string>
#include<vector>

class Primes {
	private:
		// Name of file contiaining list of prime numbers
		std::string m_filename;

		// Vector into which is read the list of prime numbers from the file
		std::vector<long long int> m_primes;

		// Number of primes to generate and store in the prime file
		int m_numPrimes{2000};

		// Reads the list of prime numbers from the file into m_primes
		std::vector<long long int> read_file(std::string filename);

		// Generates a file containingthe first max prime numbers
		void gen_file(std::string filename, int max);

		// Checks whether lhs is divisible by rhs
		bool is_divisible_by(long long int lhs, long long int rhs) { return lhs%rhs==0; }

		// Checks whether or not input is prime
		bool is_prime(long long int input);

		// Sanity checks on indices and values
		bool in_index_range(int index) { return 0 <= index <= m_primes.size(); }
		bool in_prime_range(int input) { return 1 < input && input < m_primes.back(); }

	public:
		// Constructors
		Primes(std::string filename="primes");

		// Subscript operator
		long long int operator[](int index);

		// Get filename
		std::string get_filename() const { return m_filename; }

		// Get length of m_primes
		int get_size() { return m_primes.size(); }

		// Returns the smallest prime divisor of input
		long long int get_smallest_prime_divisor(long long int input);

		// Returns a vector of the prime factors of input sorted in ascending order
		std::vector<long long int> get_prime_factors(long long int input);

		// Returns a vector containing the values of the exponents of each prime, in
		// ascending order, of the prime number decomposition of the input
		std::vector<int> get_exponent_vector(long long int input);

		// Returns smallest positive integer that is divisible by each of the
		// numbers input, input-1, input-2, ..., 3, 2
		long long int get_smallest_multiple(int input);

		// Returns the sum of all primes less than max
		long long int get_sum_to(int max);

		// Returns the GCD of the two inputs
		long long int get_gcd(long long int lhs, long long int rhs);

		// Returns the arithmetic derivative of the input
		long long int arith_deriv(long long int input);

};

#endif
