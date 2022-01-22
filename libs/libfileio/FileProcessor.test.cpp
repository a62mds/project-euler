#include "doctest.h"

#include "FileProcessor.h"


bool write_file(const std::string& filename, const std::vector<std::string>& contents) {

    std::ofstream output(filename);
    if (!output.is_open()) {
        return false;
    }

    for (const std::string& line : contents) {
        output << line + "\n";
    }

    return true;
}


TEST_CASE("Test function fileio::process_file") {

    SUBCASE("Test processing a nonexistent file fails") {
        std::function<std::string(const std::string&)> line_processor = [](const std::string& line) { return line; };
        std::vector<std::string> output;

        bool successfully_processed_file = fileio::process_file<std::string>("does_not_exist", output, line_processor);

        CHECK(!successfully_processed_file);
    }

    SUBCASE("Test basic reading and writing file") {
        std::function<std::string(const std::string&)> line_processor = [](const std::string& line) { return line; };
        std::vector<std::string> input {
            "This is a file.",
            "This file has several lines.",
            "This is the last line in the file."
        };
        write_file("test-file.txt", input);
        std::vector<std::string> output;
        
        bool successfully_processed_file = fileio::process_file<std::string>("test-file.txt", output, line_processor);

        CHECK(successfully_processed_file);
        CHECK(input == output);
    }

}
