#include<iostream>
using namespace std;

int main() {
	int n_max{4000000};
	int sum{0};
	int temp_term{0};
	int old_term{0};
	int cur_term{1};
	for (int index=1;cur_term+old_term<=n_max&&index<=100000;index++) {
		temp_term = cur_term;
		cur_term += old_term;
		old_term = temp_term;
		cout << cur_term << endl;
		if (cur_term%2==0) { sum += cur_term; }
	}
	cout << "Sum = " << sum << endl;
}
