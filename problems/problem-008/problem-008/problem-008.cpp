// problem-008.cpp
#include <algorithm>
#include <iostream>
#include <numeric>

#include <libfileio/FileProcessor.h>
#include <libmath/NaturalNumbers.h>


const std::string PROBLEM_STATEMENT_FILENAME = "problem-008.html";
const size_t NUMBER_OF_DIGITS_IN_PRODUCT = 13;


/** 
 * Compute the product of the digits in the string (which is assumed to consist entirely of digits)
 */
math::numbers::natural compute_product_of_digits(const std::string& digit_str) {

	std::vector<math::numbers::natural> digits;
	digits.resize(digit_str.size());
	std::transform(digit_str.begin(), digit_str.end(), digits.begin(), [](const char& c){ return c - '0'; });

	math::numbers::natural product = 0ull;
	if (!std::any_of(digits.begin(), digits.end(), [](math::numbers::natural d){ return d == 0; })) {
		product = std::accumulate(digits.begin(), digits.end(), 1ull, std::multiplies<math::numbers::natural>());
	}

	return product;
}

/** 
 * Strip HTML tags from a string
 * 
 * Adapted from:
 * https://stackoverflow.com/questions/49333136/removing-html-tags-from-a-string-of-text#49333561
 */
std::string strip_html_tags(const std::string& input) {

	std::string output = input;
	while (output.find("<") != std::string::npos)
	{
		auto startpos = output.find("<");
		auto endpos = output.find(">") + 1;

		if (endpos != std::string::npos)
		{
			output.erase(startpos, endpos - startpos);
		}
	}

	return output;
}

/** 
 * Filter out non-numeric strings
 * 
 * Function with the narrowly scoped purpose of reading lines of HTML, removing the tags, and, if what remains consists
 * of only digits, return that string. Otherwise, return the empty string.
 */
std::string filter_numeric_line(const std::string& line) {

	std::string output = strip_html_tags(line);

	return std::all_of(output.begin(), output.end(), iswdigit) ? output : "";
}


int main() {

	std::function<std::string(const std::string&)> line_processor = filter_numeric_line;
	std::vector<std::string> numeric_rows;
	if (!fileio::process_file(PROBLEM_STATEMENT_FILENAME, numeric_rows, line_processor)) {
		std::cerr << "Failed to process file " << PROBLEM_STATEMENT_FILENAME << std::endl;
	}

	std::string digits;
	std::for_each(numeric_rows.begin(), numeric_rows.end(), [&](const std::string& numeric_row){ digits += numeric_row; });

	std::vector<std::string> adjacent_digit_subsets;
	for (size_t start_position=0; start_position <= digits.size() - NUMBER_OF_DIGITS_IN_PRODUCT; start_position++) {
		adjacent_digit_subsets.push_back(digits.substr(start_position, NUMBER_OF_DIGITS_IN_PRODUCT));
	}

	std::vector<math::numbers::natural> products;
	products.resize(adjacent_digit_subsets.size());
	std::transform(adjacent_digit_subsets.begin(), adjacent_digit_subsets.end(), products.begin(), compute_product_of_digits);

	math::numbers::natural largest_product = *std::max_element(products.begin(), products.end());

	std::cout << largest_product << std::endl;

	return 0;
}
