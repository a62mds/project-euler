#include<iostream>
#include<vector>
using namespace std;

bool isDivisBy(long long int lhs, long long int rhs) {
	return lhs%rhs==0;
}

bool isPrime(long long int number) {
	for (long long int num=2;num<number;num++) {
		if (isDivisBy(number,num)) { return false; break; }
	}
	return true;
}

int main() {
	long long int the_number{600851475143};
	//long long int the_number{13195};
	for (int candidate=3;candidate<the_number;candidate++) {
		if ( isDivisBy(the_number,candidate) && isPrime(the_number/candidate) ) {
			cout << "Candidate             " << candidate << endl;
			cout << "Largest prime factor: " << the_number/candidate << endl;
			break;
		}
	}
}
