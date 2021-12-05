// problem-009.cpp
#include<iostream>
#include<cmath>

/*
	 inline bool is_pythag_triplet(int a, int b, int c) {
	 return sq(c) == sq(a) + sq(b);
}
template<typename T> inline bool does_sum_to(T a, T b, T c, T sum) {
	return sum == a + b + c;
}
*/

template<typename T> inline T sq(T input) { return input*input; } 

int main() {
	int P{1000};
	for (int a=3; a<P; a++) {
		for (int b=a+1; b<=P; b++) {
			if ( P == sqrt(sq(a)+sq(b))+(a+b) ) {
				std::cout << "a = " << a << std::endl;
				std::cout << "b = " << b << std::endl;
				std::cout << "c = " << P-(a+b) << std::endl;
				std::cout << "a*b*c = " << a*b*(P-(a+b)) << std::endl;
				return 0;
			}
		}
	}

    return 0;
}
