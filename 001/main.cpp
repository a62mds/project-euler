#include<iostream>
using namespace std;

int main() {
	int n_max{1000};
	int sum{0};
	for(int num=1;num!=n_max;num++){ if(num%3==0||num%5==0){ sum+=num; } }
	cout << "Sum = " << sum << endl;
}
