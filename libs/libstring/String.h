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

std::string join(const std::vector<std::string>& tokens, char delimiter) {
    std::ostringstream oss;
    auto it = tokens.begin();
    if (it != tokens.end()) {
        oss << *it++;
        for (; it != tokens.end(); ++it) {
            oss << delimiter << *it;
        }
    }
    return oss.str();
}

bool is_numeric(const std::string& str) {
    if (str.empty()) {
        return false;
    }
    return std::all_of(str.begin(), str.end(), isdigit);
}

}; // namespace string

#endif
