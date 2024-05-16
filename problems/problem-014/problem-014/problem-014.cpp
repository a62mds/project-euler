// problem-014.cpp
#include <iostream>

#include <libmath/NaturalNumbers.h>


math::numbers::natural MAX_INITIAL_VALUE = 1000000;


size_t get_chain_length(math::numbers::natural initial_value) {
    math::sequences::CollatzNumbers c(initial_value);
    size_t chain_length = 1;
    while (c.next() != 1) {
        chain_length++;
    }
    return chain_length;
}


int main() {
    size_t max_chain_length = 0;
    math::numbers::natural max_chain_length_initial_value = 1;
    for (math::numbers::natural initial_value = 1; initial_value <= MAX_INITIAL_VALUE; ++initial_value) {
        size_t chain_length = get_chain_length(initial_value);
        if (chain_length > max_chain_length) {
            max_chain_length = chain_length;
            max_chain_length_initial_value = initial_value;
            std::cout << "Updating: " << max_chain_length_initial_value << ": " << max_chain_length << std::endl;
        }
    }
    std::cout << "Answer: " << max_chain_length_initial_value << ": " << max_chain_length << std::endl;
    return 0;
}
