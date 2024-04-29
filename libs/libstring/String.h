#ifndef STRING_H
#define STRING_H

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>


namespace string {

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

bool is_numeric(const std::string& str) {
    if (str.empty()) {
        return false;
    }
    return std::all_of(str.begin(), str.end(), isdigit);
}

}; // namespace string

#endif
