// problem-004.cpp
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

// Convert integer to string
string int_to_string(int number) {
	stringstream ss;
	ss << number;
	return ss.str();
}

// Convert string (containing an integer number) to integer
int string_to_int(string input) {
	stringstream ss;
	ss << input;
	int output{0};
	ss >> output;
	return output;
}

// Reverse the order of the characters in a string (return backward string)
string reverse(string input) {
	stringstream ss;
	// range between string::rbegin and string::rend contains all the characters
	// of the string in reverse order
	for (string::reverse_iterator rit=input.rbegin();rit!=input.rend();rit++) {
		ss << *rit;
	}
	return ss.str();
}

// Takes a string of length n and returns creates a palindromic string of
// length 2n by concatinating input and reverse(input)
string palindrome(string input) {
	stringstream ss;
	ss << input << reverse(input);
	return ss.str();
}

// Test if input is a three digit number
bool is_three_digits(int input) { return 100 <= input && input <= 999; }
// Test whether lhs is divisible by rhs
bool is_divisble_by(int lhs, int rhs) { return lhs%rhs==0; }

// Test whether input is the product of two three digit numbers
bool is_prod_three(int input) {
	for (int num=100; num <= 999; num++) {
		if (is_divisble_by(input,num)&&is_three_digits(input/num)) { return true; }
	}
	return false;
}

int main() {
	int n_pal{0};		// initialize variable for holding palindromic integers
	// Run through all three digit numbers from 999 backwards to 100
	for (int num=999; num >= 100; num--) {
		// create 6 digit palindrome from three digit number
		n_pal = string_to_int(palindrome(int_to_string(num)));
		// Test whether it is a product of two three digit numbers
		if (is_prod_three(n_pal)) {
			cout << "\n  >>  " << n_pal << endl;
			break;
		}
	}

    return 0;
}
