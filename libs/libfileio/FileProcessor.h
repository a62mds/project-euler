#ifndef FILE_IO_H
#define FILE_IO_H

#include <fstream>
#include <functional>
#include <string>
#include <vector>


namespace fileio {

/**
 * @brief 
 * 
 * @param output 
 * @param filename 
 * @param line_processor 
 * @return true 
 * @return false 
 */
template <typename T>
bool process_file(const std::string& filename, std::vector<T>& output, std::function<T(const std::string&)> line_processor) {

    std::ifstream input(filename);
    if (!input.is_open()) {
        return false;
    }

    bool success = true;
    std::string line;
    while (std::getline(input, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        output.push_back(line_processor(line));
    }

    return success;
}

} // namespace fileio

#endif
