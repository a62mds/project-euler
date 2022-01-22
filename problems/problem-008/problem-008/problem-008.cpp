// problem-008.cpp
#include <algorithm>
#include <iostream>

#include <libfileio/FileProcessor.h>


inline int ctoi(char c) { return c - '0'; }

long long int find_prod(const std::string& digits) {
	long long int product{1};
	int digit{0};
	for (std::string::const_iterator iit=digits.begin(); iit!=digits.end(); ++iit) {
		digit = ctoi(*iit);
		if (digit==0) { return 0; } else { product *= digit; }
	}
	return product;
}

long long int find_largest_product(std::string& numbers, int num_adj) {
	int offset{num_adj-1};
	long long int maxprod{1};
	long long int currprod{1};
	for (std::string::iterator it=numbers.begin(); it!=(numbers.end()-offset); ++it) {
		std::string substr;
		for (int count=0; count<=offset; count++) {
			substr+=*(it+count);
		}
		currprod = find_prod(substr);
		if (currprod > maxprod)  maxprod = currprod;
	}
	return maxprod;
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
	if (!fileio::process_file("problem-008.html", numeric_rows, line_processor)) {
		std::cerr << "Failed to process file " << "problem-008.html" << std::endl;
	}

	std::string digits;
	std::for_each(numeric_rows.begin(), numeric_rows.end(), [&](const std::string& numeric_row){ digits += numeric_row; });

	std::cout << find_largest_product(digits, 13) << std::endl;

	return 0;
}
