//=============================================================================
// Definitions for class Primes
//=============================================================================
#include"Primes.h"

//=============================================================================
//
// Reads an indexed list of prime numbers from a file whose name is specified
// as input and outputs a std::vector<int> of the primes
std::vector<int> Primes::read_file(const std::string& filename) {
	std::vector<int> output;			// vector for storing prime numbers
	std::ifstream ifs(filename);	// create ifstream from prime number file

	// Each line of the file has the index of the prime number and the prime
	// number itself. The values are tab-separated
	std::string line;								// holds each line, ie each index, prime pair
	while (std::getline(ifs,line)) {
		std::istringstream iss(line);	// feed each line, i.e. each index, prime
		int key, value;								// pair, one at a time into iss until there
		if (!(iss >> key >> value)) { // is no line to read, at which time the eof
			break;											// has been reached 
		}
		else {												// until that happens,
			iss >> key >> value;				// store index and prime number as ints
			output.push_back(value);		// push back prime number into output vector
		}
	}

	return output;
}

//=============================================================================
//
// Checks the whether input is prime by comparing it against the primes stored
// in the member variable std::vector<int> m_primes
bool Primes::is_prime(int input) {
	// Sanity check (currently only works for integers up to the max indicated)
	if (not in_prime_range(input))
		throw std::invalid_argument("Input must be within range [2,17389]");

	// Traverse the vector of primes from smallest to largest looking for input
	for (std::vector<int>::iterator it=m_primes.begin(); it!=m_primes.end(); ++it)
		if (input == *it) return true;
	// If not found, number is not prime
	return false;
}

//=============================================================================
//
// Subscript operator
int Primes::operator[](int index) {
	// Sanity check
	if (not in_index_range(index))
		throw std::invalid_argument("Index must be within range [1,1999]");
	// if 0th prime is requested, return 1
	else if (index == 0) return 1;
	// else return the appropriate element of n_primes (starts at 2)
	else return m_primes[index-1];
}

//=============================================================================
//
// Find the smallest prime divisor of an integer
int Primes::get_smallest_prime_divisor(int input) {
	// Traverse the vector of primes checking the divisibility of input by each
	for (std::vector<int>::iterator it=m_primes.begin(); it!=m_primes.end(); ++it)
		if (is_divisible_by(input,*it)) return *it;
	// if no divisors found, throw an out of range exception
	throw std::out_of_range("No prime divisors < 17389 found");
}

//=============================================================================
//
// Returns a vector containing the prime factors (with repetition) of the input
std::vector<int> Primes::get_prime_factors(int input) {
	std::vector<int> output;
	// 
	int quotient{input};
	while (quotient != 1) {
		// Find the smallest prime divisor of the quotient
		int smallest_prime_divisor = get_smallest_prime_divisor(quotient);
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
std::vector<int> Primes::get_exponent_vector(int input) {
	std::vector<int> output;
	std::vector<int> prime_factors{get_prime_factors(input)};
	int count{0};							// holds multiplicity of each prime in prime_factors
	int running_product{1};		// helps eliminate unnecessary trailing zeros
	// Traverse m_primes and count how many times each prime number appears in
	// the prime number decomposition of input
	for (std::vector<int>::iterator it=m_primes.begin(); it!=m_primes.end(); ++it) {
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
// M. Sullivan. June, 2016
