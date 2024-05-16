// problem-013.cpp
#include <iostream>

#include <libfileio/FileProcessor.h>
#include <libfunctional/Reduce.h>
#include <libhtml/Html.h>
#include <libmath/BigNumbers.h>
#include <libstring/String.h>


const std::string PROBLEM_STATEMENT_FILENAME = "problem-013.html";


std::vector<math::bignumbers::BigNumber> read_numbers(const std::string& filename) {
    std::function<math::bignumbers::BigNumber(const std::string&)> line_processor = [](const std::string& line){
        std::string text = html::strip_tags(line);
        return string::is_numeric(text) ? math::bignumbers::BigNumber(text): math::bignumbers::BigNumber("0");
    };

    std::vector<math::bignumbers::BigNumber> numbers;
    if (!fileio::process_file(filename, numbers, line_processor)) {
        throw std::ios_base::failure("Failed to process file " + filename);
    }

    return numbers;
}

int main() {
    std::vector<math::bignumbers::BigNumber> numbers = read_numbers(PROBLEM_STATEMENT_FILENAME);

    math::bignumbers::BigNumber zero("0");

    std::function<math::bignumbers::BigNumber(const math::bignumbers::BigNumber&, const math::bignumbers::BigNumber&)> add = [](const math::bignumbers::BigNumber& left, const math::bignumbers::BigNumber& right) {
        return left + right;
    };

    math::bignumbers::BigNumber sum = functional::reduce(numbers, zero, add);

    std::cout << sum.to_string().substr(0, 10) << std::endl;

    return 0;
}
