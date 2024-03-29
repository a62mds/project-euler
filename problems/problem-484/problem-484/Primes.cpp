//=============================================================================
// Definitions for class Primes
//=============================================================================
#include"Primes.h"
#include<iostream>

//=============================================================================
//
// Constructors
Primes::Primes(std::string filename/*="primes"*/) : m_filename{filename} {
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
int Primes::operator[](int index) {
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
//
// Reads a list of prime numbers from a file whose name is specified
// as input and outputs a std::vector<int> containing the primes
std::vector<long long int> Primes::read_file(std::string filename) {
	std::vector<long long int> output;			// vector for storing prime numbers
	std::ifstream ifs(filename);	// create ifstream from prime number file
	if (!ifs) throw std::ios_base::failure("Could not open " + filename);
	
	long long int value;
	while (!ifs.eof()) {
		ifs >> value;
		output.push_back(value);
	}

	return output;
}

//=============================================================================
//
// Generates a file containing the first max prime numbers
void Primes::gen_file(std::string filename, int max) {
	bool is_prime = true;
	int num{3};
	std::ofstream output(filename);
	std::vector<long long int> primes; 
	primes.push_back(2);
	while (primes.size() < max) {
		for (std::vector<long long int>::iterator it=primes.begin(); it!=primes.end(); ++it) { 
			if (is_divisible_by(num, *it) && num!=*it) { is_prime=false; break; }
		}
		if (is_prime) { primes.push_back(num); }
		num+=2; is_prime=true;
	}
	for (std::vector<long long int>::iterator it=primes.begin(); it!=primes.end(); ++it) {
		output << *it << std::endl;
	}
	output.close();
}

//=============================================================================
//
// Checks the whether input is prime by comparing it against the primes stored
// in the member variable std::vector<int> m_primes
bool Primes::is_prime(long long int input) {
	// Sanity check (currently only works for integers up to the max indicated)
	if (!in_prime_range(input))
		throw std::invalid_argument("Input must be within range [2,17389]");

	// Traverse the vector of primes from smallest to largest looking for input
	for (std::vector<long long int>::iterator it=m_primes.begin(); it!=m_primes.end(); ++it)
		if (input == *it) return true;
	// If not found, number is not prime
	return false;
}

//=============================================================================
//
// Find the smallest prime divisor of an integer
long long int Primes::get_smallest_prime_divisor(long long int input) {
	// Traverse the vector of primes checking the divisibility of input by each
	for (std::vector<long long int>::iterator it=m_primes.begin(); it!=m_primes.end(); ++it)
		if (is_divisible_by(input,*it)) return *it;
	// if no divisors found, throw an out of range exception
	throw std::out_of_range("No prime divisors < 17389 found");
}

//=============================================================================
//
// Returns a vector containing the prime factors (with repetition) of the input
std::vector<long long int> Primes::get_prime_factors(long long int input) {
	std::vector<long long int> output;
	// 
	long long int quotient{input};
	while (quotient != 1) {
		// Find the smallest prime divisor of the quotient
		long long int smallest_prime_divisor = get_smallest_prime_divisor(quotient);
		// Add to the vector of prime divisors
		output.push_back(smallest_prime_divisor);
		// Divide out the smallest prime divisor for the next iteration
		quotient /= smallest_prime_divisor;

		if (quotient == 1) break;
		// Check whether the quotient is prime; if it is, all prime divisors have
		// been found. Add to the vector of prime divisors and exit the loop
		if (is_prime(quotient)) { output.push_back(quotient); break; }
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
std::vector<int> Primes::get_exponent_vector(long long int input) {
	std::vector<int> output;
	std::vector<long long int> prime_factors{get_prime_factors(input)};
	int count{0};							// holds multiplicity of each prime in prime_factors
	long long int running_product{1};		// helps eliminate unnecessary trailing zeros
	// Traverse m_primes and count how many times each prime number appears in
	// the prime number decomposition of input
	for (std::vector<long long int>::iterator it=m_primes.begin(); it!=m_primes.end(); ++it) {
		if (*it > input) break;
		count = std::count(prime_factors.begin(), prime_factors.end(), *it);
		// Push back the count into the output vector, recording the exponent of the
		// prime number
		output.push_back(count);
		// Keep track of the size of the product of all of the prime factors
		// discovered thus far. When the product equals the input, the entire
		// prime decomposition of input has been found, so exit the loop
		running_product *= pow(*it, count);
		if (running_product >= input) break;
	}
	return output;
}


//=============================================================================
//
// Returns smallest positive integer that is divisible by each of the
// numbers input, input-1, input-2, ..., 3, 2
long long int Primes::get_smallest_multiple(int input) {
	std::vector<int> master_exponent_vector{get_exponent_vector(input)};
	std::vector<int> inner_exponent_vector;
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
	long long int output{1};
	for (int ii=0; ii!=master_exponent_vector.size(); ii++)
		output *= pow(m_primes[ii],master_exponent_vector[ii]);
	return output;
}

long long int Primes::get_sum_to(int max) {
	long long int sum{0};
	for (std::vector<int>::iterator it=m_primes.begin(); it!=m_primes.end() && *it<max; ++it) {
		sum += *it;
	}
	return sum;
}

//=============================================================================
//
// Returns GCD of the two inputs
long long int Primes::get_gcd(long long int lhs, long long int rhs) {
	long long int min{lhs <= rhs ? lhs : rhs};
	for (long long int denom=min; denom>=1; denom--) {
		if (is_divisible_by(lhs,denom) && is_divisible_by(rhs,denom))
			return denom;
	}
}

//=============================================================================
//
// Returns the arithmetic derivative of 
long long int Primes::arith_deriv(long long int input) {
	if (is_prime(input)) { 
		return 1;
	}
	else {
		long long int lpd{get_smallest_prime_divisor(input)};
		long long int qt{input/lpd};
		return qt + lpd*arith_deriv(qt);	
	}
}
// M. Sullivan. June, 2016
