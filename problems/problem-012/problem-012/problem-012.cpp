// problem-012.cpp
#include <iostream>

#include <libmath/NaturalNumbers.h>


int main() {
    math::sequences::TriangleNumbers triangle_numbers;
    while (true) {
        math::numbers::natural current_triangle_number = triangle_numbers.next();
        std::unordered_set<math::numbers::natural> divisors = math::get_divisors(current_triangle_number);
        if (divisors.size() >= 500) {
            std::cout << current_triangle_number << std::endl;
            break;
        }
    }
    return 0;
}
