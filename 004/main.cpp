#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string int_to_string(int number) {
	stringstream ss;
	ss << number;
	return ss.str();
}

int string_to_int(string input) {
	stringstream ss;
	ss << input;
	int output{0};
	ss >> output;
	return output;
}

string reverse(string input) {
	stringstream ss;
	for (string::reverse_iterator rit=input.rbegin();rit!=input.rend();rit++) {
		ss << *rit;
	}
	return ss.str();
}

string palindrome(string input) {
	stringstream ss;
	ss << input << reverse(input);
	return ss.str();
}

bool is_three_digits(int input) { return 99 <= input && input <= 999; }
bool is_divisble_by(int lhs, int rhs) { return lhs%rhs==0; }

bool is_prod_three(int input) {
	for (int num=100;num<=999;num++) {
		if (is_divisble_by(input,num)&&is_three_digits(input/num)) { return true; }
	}
	return false;
}

int main() {
	int n_pal=0;
	for (int n_max=999;n_max>=100;n_max--) {
		n_pal = string_to_int(palindrome(int_to_string(n_max)));
		if (is_prod_three(n_pal)) {
			cout << "\n  >>  " << n_pal << endl;
			break;
		}
	}
}
