#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<algorithm>

// reads a list of prime numbers into a std::vector<int>
std::vector<int> read_file(const std::string& filename) {

	std::vector<int> output;			// vector storing prime numbers
	std::ifstream ifs(filename);	// create ifstream from prime number file

	// Each line of the file has the index of the prime number and the prime
	// number itself. The values are tab-separated
	std::string line;
	while (std::getline(ifs,line)) {
		std::istringstream iss(line);
		int key, value;
		if (!(iss >> key >> value)) { // if no line to read
			break;
		}
		else {
			iss >> key >> value;				// store index and prime number as ints
			output.push_back(value);		// push back prime number into output vector
		}
	}

	return output;
}

bool is_divisible_by(long long int lhs, long long int rhs) {
	return lhs%rhs==0;
}

int main() {
	std::string filename{"primes"};
	std::vector<int> primes = read_file(filename);

	// create a list of prime factors of the number
	long long int the_number{600851475143};
	std::vector<int> prime_factors;
	for (std::vector<int>::iterator it=primes.begin(); it!=primes.end(); ++it) {
		if (is_divisible_by(the_number,*it)) prime_factors.push_back(*it);
	}

	// std::max_element() returns an iterator pointing to the address of the
	// max element in the vector prime_factors, hence the use of the deref
	// operator in the second line
	std::cout << "Largest prime divisor: " 
						<< *std::max_element(prime_factors.begin(), prime_factors.end())
						<< std::endl;
}
