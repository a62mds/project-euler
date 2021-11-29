#include<iostream>
using namespace std;

int main() {

	int n_max{4000000}; // upper bound
	int sum{0};					// running total
	int temp_term{0};		// temporary value to help navigate the Fib. sequence
	int old_term{0};		// previous term in the sequence
	int cur_term{1};		// current term in the sequence

	for (int index=1;cur_term+old_term<=n_max&&index<=100000;index++) {
		// calculate next term in the sequence and update old_term appropriately
		temp_term = cur_term;
		cur_term += old_term;
		old_term = temp_term;

		// add curr_term to running total if it is even
		if (cur_term%2==0) { sum += cur_term; }
	}

	cout << "Sum = " << sum << endl;
}
