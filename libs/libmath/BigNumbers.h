#ifndef BIGNUMBERS_H
#define BIGNUMBERS_H

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>


namespace math {

namespace bignumbers {

class BigNumber {
public:
    BigNumber(const std::string& number) {
        validate(number);
        parse(remove_leading_zeros(number));
    }

    std::string to_string() const {
        return vec_to_string(digits);
    }

    size_t num_digits() const {
        return digits.size();
    }

    friend bool operator==(const BigNumber& left, const BigNumber& right) {
        return left.digits == right.digits;
    }

    friend BigNumber operator+(const BigNumber& left, const BigNumber& right) {
        std::vector<int> digits;
        digits.reserve(std::max(left.digits.size(), right.digits.size()) + 1);

        int left_summand, right_summand, sum;
        int carry = 0;

        auto this_it = left.digits.begin();
        auto other_it = right.digits.begin();
        while (this_it != left.digits.end() || other_it != right.digits.end()) {
            left_summand = this_it == left.digits.end() ? 0 : *this_it++;
            right_summand = other_it == right.digits.end() ? 0 : *other_it++;
            sum = left_summand + right_summand + carry;
            carry = sum / 10;
            digits.push_back(sum % 10);
        }

        if (carry) {
            digits.push_back(carry);
        }

        return BigNumber(vec_to_string(digits));
    }

private:
    void validate(const std::string& number) {
        if (number.empty()) {
            throw std::invalid_argument("Empty string passed to BigNumber constructor");
        }

        if (!std::all_of(number.begin(), number.end(), isdigit)) {
            throw std::invalid_argument("Not a number: " + number);
        }
    }

    std::string remove_leading_zeros(std::string number) {
        number.erase(0, std::min(number.find_first_not_of('0'), number.size()-1));
        return number;
    }

    void parse(const std::string& number) {
        // Stores the digits in order from least significant to most significant
        digits.reserve(number.size());
        for (auto it = number.rbegin(); it != number.rend(); ++it) {
            digits.push_back(*it - '0');
        }
    }

    static std::string vec_to_string(const std::vector<int>& vec) {
        std::string number;
        for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
            number.append(std::to_string(*it));
        }
        return number;
    }

    std::vector<int> digits;
};

}; // namespace bignumbers

}; // namespace math

#endif
