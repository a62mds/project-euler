#ifndef STRING_H
#define STRING_H

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

}; // namespace string

#endif
