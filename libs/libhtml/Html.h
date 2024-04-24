#ifndef HTML_H
#define HTML_H

#include <regex>
#include <string>

namespace html {

    std::regex TAG_REGEX("<[^<]*>");

    std::string strip_tags(const std::string &input) {
        std::string output;

        std::regex_replace(std::back_inserter(output), input.begin(), input.end(), TAG_REGEX, "");

        return output;
    }

}; // namespace html

#endif
