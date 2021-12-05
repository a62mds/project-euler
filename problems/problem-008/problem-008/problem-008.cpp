// problem-008.cpp
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

bool is_all_digits(std::string& line) {
	return std::all_of(line.begin(), line.end(), ::iswdigit);
}

inline int ctoi(char c) { return c - '0'; }

std::string read_file(std::string filename) {
	// read file
	std::ifstream ifs(filename);
	std::string line;
	std::string numbers;
	std::cout << numbers << std::endl;
	while (std::getline(ifs,line)) {
		// If line consists exclusively of digits, append it to the string of numbers
		if (is_all_digits(line)) numbers+=line;
	}
	return numbers;
}

long long int find_prod(std::string& digits) {
	long long int product{1};
	int digit{0};
	for (std::string::iterator iit=digits.begin(); iit!=digits.end(); ++iit) {
		//std::cout << *it << std::endl;
		digit = ctoi(*iit);
		if (digit==0) { return 0; } else { product *= digit; }
		//std::cout << product << std::endl;
	}
	return product;
}

long long int find_largest_product(std::string& numbers, int num_adj) {
	int offset{num_adj-1};
	long long int maxprod{1};
	long long int currprod{1};
	for (std::string::iterator it=numbers.begin(); it!=(numbers.end()-offset); ++it) {
		std::string substr;
		for (int count=0; count<=offset; count++) {
			substr+=*(it+count);
			//std::cout << substr << std::endl;
		}
		currprod = find_prod(substr);
		std::cout << substr << " : " <<  currprod << std::endl;
		if (currprod > maxprod)  maxprod = currprod;
	}
	return maxprod;
}

int main() {
	std::string numbers = read_file("problem-008.txt");
	std::cout << find_largest_product(numbers, 13) << std::endl;

    return 0;
}
