//=============================================================================
// Definitions for class Primes
//=============================================================================
#include <algorithm>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "PrimeNumbers.h"


namespace math {

//=============================================================================
//
// Constructors
sequences::Primes::Primes(std::string filename/*="primes"*/, size_t maxnum/*=2000*/) : m_filename{filename}, m_numPrimes{maxnum} {
	try {
		m_primes = read_file(m_filename);
	} catch(std::ios_base::failure) {
		gen_file(m_filename, m_numPrimes);
		m_primes = read_file(m_filename);
	}
}

//=============================================================================
//
// Subscript operator
numbers::natural sequences::Primes::operator[](int index) {
	// Sanity check
	if (!in_index_range(index))
		throw std::invalid_argument("Index must be within range [1,1999]");
	// if 0th prime is requested, return 1
	else if (index == 0) return 1;
	// else return the appropriate element of n_primes (starts at 2)
	else return m_primes[index-1];
}

//=============================================================================
//
// Reads a list of prime numbers from a file whose name is specified
// as input and outputs a std::vector<int> containing the primes
std::vector<numbers::natural> sequences::Primes::read_file(std::string filename) {
	std::vector<numbers::natural> output;			// vector for storing prime numbers
	std::ifstream ifs(filename);	// create ifstream from prime number file
	if (!ifs) throw std::ios_base::failure("Could not open " + filename);
	
	numbers::natural value;
	while (!ifs.eof()) {
		ifs >> value;
		output.push_back(value);
	}

	return output;
}

//=============================================================================
//
// Generates a file containing the first max prime numbers
void sequences::Primes::gen_file(std::string filename, size_t max) {
	bool is_prime = true;
	int num{3};
	std::ofstream output(filename);
	std::vector<numbers::natural> primes; 
	primes.push_back(2);
	while (primes.size() < max) {
		for (std::vector<numbers::natural>::iterator it=primes.begin(); it!=primes.end(); ++it) { 
			if (is_divisible_by(num, *it) && num!=*it) { is_prime=false; break; }
		}
		if (is_prime) { primes.push_back(num); }
		num+=2; is_prime=true;
	}
	for (std::vector<numbers::natural>::iterator it=primes.begin(); it!=primes.end(); ++it) {
		output << *it << std::endl;
	}
	output.close();
}

//=============================================================================
//
// Checks the whether input is prime by comparing it against the primes stored
// in the member variable std::vector<int> m_primes
bool sequences::Primes::is_prime(numbers::natural input) {
	// Sanity check (currently only works for integers up to the max indicated)
	if (!in_prime_range(input))
		throw std::invalid_argument("Input must be within range [2, " + std::to_string(m_primes.back()) + "]");

	// Traverse the vector of primes from smallest to largest looking for input
	for (std::vector<numbers::natural>::iterator it=m_primes.begin(); it!=m_primes.end(); ++it)
		if (input == *it) return true;
	// If not found, number is not prime
	return false;
}

//=============================================================================
//
// Find the smallest prime divisor of an integer
numbers::natural sequences::Primes::get_smallest_prime_divisor(numbers::natural input) {
	for (auto& prime_number : m_primes) {
		if (is_divisible_by(input, prime_number)) {
			return prime_number;
		}
	}

	throw std::out_of_range("No prime divisors < " + std::to_string(m_primes.back()) + " found");
}

//=============================================================================
//
// Returns a vector containing the prime factors (with repetition) of the input, sorted in ascending order
std::vector<numbers::natural> sequences::Primes::get_prime_factors(numbers::natural input) {
	std::vector<numbers::natural> output;
	numbers::natural quotient{input};
	while (quotient != 1) {
		numbers::natural smallest_prime_divisor = get_smallest_prime_divisor(quotient);
		output.push_back(smallest_prime_divisor);
		// Check whether the quotient is prime; if it is, all prime divisors have
		// been found
		if (quotient == smallest_prime_divisor) {
			break;
		}

		quotient /= smallest_prime_divisor;
	}
	// Sort the vector of prime divisors from smallest to largest. Note that 
	// the multiplicity of each divisor can be > 1 (e.g. get_prime_factors(8) will
	// return the vector <2,2,2>)
	std::sort(output.begin(), output.end());
	return output;
}

//=============================================================================
//
// Returns a vector containing the values of the exponents of each prime, in
// ascending order, of the prime number decomposition of the input
std::vector<size_t> sequences::Primes::get_exponent_vector(numbers::natural input) {
	std::vector<size_t> output;
	std::vector<numbers::natural> prime_factors{get_prime_factors(input)};
	size_t count{0};						// holds multiplicity of each prime in prime_factors
	numbers::natural running_product{1};		// helps eliminate unnecessary trailing zeros
	// Traverse m_primes and count how many times each prime number appears in
	// the prime number decomposition of input
	for (std::vector<numbers::natural>::iterator it=m_primes.begin(); it!=m_primes.end(); ++it) {
		if (*it > input) break;
		count = std::count(prime_factors.begin(), prime_factors.end(), *it);
		// Push back the count into the output vector, recording the exponent of the
		// prime number
		output.push_back(count);
		// Keep track of the size of the product of all of the prime factors
		// discovered thus far. When the product equals the input, the entire
		// prime decomposition of input has been found, so exit the loop
		for (size_t mult_count=0; mult_count < count; mult_count++) {
			running_product *= *it;
		}
		if (running_product >= input) break;
	}
	return output;
}


//=============================================================================
//
// Returns smallest positive integer that is divisible by each of the
// numbers input, input-1, input-2, ..., 3, 2
numbers::natural sequences::Primes::get_smallest_multiple(int input) {
	std::vector<size_t> master_exponent_vector{get_exponent_vector(input)};
	std::vector<size_t> inner_exponent_vector;
	for (int number=input-1; number >= 2; number--) {
		inner_exponent_vector = get_exponent_vector(number);
		// ensure master vector is not shorter than exponent vector of current number
		if (master_exponent_vector.size() < inner_exponent_vector.size())
			master_exponent_vector.resize(inner_exponent_vector.size());
		// compare each vector element-by-element and update master with larger element
		for (int ii=0;	ii != inner_exponent_vector.size(); ii++)
			if (master_exponent_vector[ii] < inner_exponent_vector[ii])
				master_exponent_vector[ii] = inner_exponent_vector[ii];
	}
	// compute the result using the master exponent vector
	numbers::natural output{1};
	for (int ii=0; ii!=master_exponent_vector.size(); ii++) {
		for (size_t count=0; count < master_exponent_vector[ii]; count++) {
			output *= m_primes[ii];
		}
	}
	return output;
}

//=============================================================================
//
// Returns the sum of the prime numbers less than the specified maximum
numbers::natural sequences::Primes::get_sum_to(int max) {
	numbers::natural sum{0};
	for (std::vector<numbers::natural>::iterator it=m_primes.begin(); it!=m_primes.end() && *it<max; ++it) {
		sum += *it;
	}
	return sum;
}

//=============================================================================
//
// Returns the arithmetic derivative of the input
numbers::natural sequences::Primes::arith_deriv(numbers::natural input) {
	if (is_prime(input)) { 
		return 1;
	}
	else {
		numbers::natural lpd{get_smallest_prime_divisor(input)};
		numbers::natural qt{input/lpd};
		return qt + lpd*arith_deriv(qt);	
	}
}

}; // namespace math
