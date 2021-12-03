#include<iostream>
using namespace std;

int main() {

	int n_max{1000}; 	// upper bound
	int sum{0};				// initialize running total

	// check each num < 1000 to see if it is divisible by either 3 or 5
	// if it is, add it to the running total
	for (int num=1; num != n_max; num++)
		if ( (num%3 == 0) || (num%5 == 0) )
			sum += num;

	cout << "Sum = " << sum << endl;

	return 0;
}
