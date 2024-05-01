// problem-011.cpp
#include <algorithm>
#include <iostream>
#include <stdexcept>

#include <libfileio/FileProcessor.h>
#include <libfunctional/Filter.h>
#include <libfunctional/Map.h>
#include <libhtml/Html.h>
#include <libmath/Matrix.h>
#include <libstring/String.h>


const std::string PROBLEM_STATEMENT_FILENAME = "problem-011.html";
const size_t NUM_ADJACENT_NUMBERS = 4;


std::vector<int> tokenize_line(const std::string& line) {

	std::string output = html::strip_tags(line);
    std::vector<std::string> tokens = string::split(output, ' ');

    if (std::all_of(tokens.begin(), tokens.end(), string::is_numeric)) {
        std::function<int(const std::string&)> to_int = [](const std::string& str) {
            return std::stoi(str);
        };
        return functional::map(tokens, to_int);
    }

	return std::vector<int>();
}

math::matrices::Matrix<int> read_matrix(const std::string& filename) {

	std::function<std::vector<int>(const std::string&)> line_processor = tokenize_line;
	std::vector<std::vector<int>> tokenized_lines;
	if (!fileio::process_file(filename, tokenized_lines, line_processor)) {
        throw std::ios_base::failure("Failed to process file " + PROBLEM_STATEMENT_FILENAME);
	}
    std::function<bool(const std::vector<int>&)> filter_line = [](const std::vector<int>& row){
        return !row.empty();
    };
    std::vector<std::vector<int>> matrix_rows = functional::filter(tokenized_lines, filter_line);
    
    return math::matrices::Matrix<int>{matrix_rows};
}

std::vector<math::matrices::Matrix<int>> get_submatrices(
    const math::matrices::Matrix<int>& matrix,
    std::pair<size_t, size_t> submatrix_shape
) {

    size_t max_row_start_index = matrix.shape().first - submatrix_shape.first;
    size_t max_col_start_index = matrix.shape().second - submatrix_shape.second;
    std::vector<math::matrices::Matrix<int>> submatrices;
    for (size_t row_index = 0; row_index < max_row_start_index; ++row_index) {
        for (size_t col_index = 0; col_index < max_col_start_index; ++col_index) {
            submatrices.push_back(matrix.submatrix(
                row_index,
                col_index,
                submatrix_shape.first,
                submatrix_shape.second
            ));
        }
    }

    for (auto& submatrix : submatrices) {
        std::pair<size_t, size_t> shape = submatrix.shape();
        if (shape.first != submatrix_shape.first || shape.second != submatrix_shape.second) {
            throw std::runtime_error(
                "Inconsistent submatrix size: "
                + std::to_string(shape.first) + " x " + std::to_string(shape.second)
            );
        }
    }

    return submatrices;
}

std::function<math::matrices::Matrix<int>(const math::matrices::Matrix<int>&)> get_products_of_rows = [](const math::matrices::Matrix<int>& matrix) {
    
    return matrix.collapse_rows([](int a, int b) { return a * b; });
};

std::function<math::matrices::Matrix<int>(const math::matrices::Matrix<int>&)> get_products_of_columns = [](const math::matrices::Matrix<int>& matrix) {
    
    return matrix.collapse_columns([](int a, int b) { return a * b; });
};

std::function<math::matrices::Matrix<int>(const math::matrices::Matrix<int>&)> get_max_in_column = [](const math::matrices::Matrix<int>& column) {
    
    return column.collapse_columns([](int a, int b) { return std::max(a, b); });
};

std::function<math::matrices::Matrix<int>(const math::matrices::Matrix<int>&)> get_max_in_row = [](const math::matrices::Matrix<int>& row) {
    
    return row.collapse_rows([](int a, int b) { return std::max(a, b); });
};

std::function<int(const math::matrices::Matrix<int>&)> get_product_of_primary_diagonals = [](const math::matrices::Matrix<int>& matrix) {
    
    return matrix.collapse_primary_diagonal([](int a, int b) { return a * b; });
};

std::function<int(const math::matrices::Matrix<int>&)> get_product_of_secondary_diagonals = [](const math::matrices::Matrix<int>& matrix) {
    
    return matrix.collapse_secondary_diagonal([](int a, int b) { return a * b; });
};

std::function<int(const math::matrices::Matrix<int>&)> get_first_element = [](const math::matrices::Matrix<int>& singleton) { return singleton.get(0, 0); };

std::vector<int> get_max_products_of_rows(const std::vector<math::matrices::Matrix<int>>& matrices) {
    
    std::vector<math::matrices::Matrix<int>> products_of_rows = functional::map(matrices, get_products_of_rows);
    std::vector<math::matrices::Matrix<int>> max_products_of_rows = functional::map(products_of_rows, get_max_in_column);

    return functional::map(max_products_of_rows, get_first_element);
}

std::vector<int> get_max_products_of_columns(const std::vector<math::matrices::Matrix<int>>& matrices) {
    
    std::vector<math::matrices::Matrix<int>> products_of_columns = functional::map(matrices, get_products_of_columns);
    std::vector<math::matrices::Matrix<int>> max_products_of_columns = functional::map(products_of_columns, get_max_in_row);

    return functional::map(max_products_of_columns, get_first_element);
}

std::vector<int> get_products_of_primary_diagonals(const std::vector<math::matrices::Matrix<int>>& matrices) {
    
    return functional::map(matrices, get_product_of_primary_diagonals);
}

std::vector<int> get_products_of_secondary_diagonals(const std::vector<math::matrices::Matrix<int>>& matrices) {
    
    return functional::map(matrices, get_product_of_secondary_diagonals);
}

std::vector<int> flatten(const std::vector<std::vector<int>>& vectors) {
    
    std::vector<int> flattened;
    for (const auto& vector : vectors) {
        flattened.insert(flattened.end(), vector.begin(), vector.end());
    }
    return flattened;
}

int get_max_product(const std::vector<math::matrices::Matrix<int>>& matrices) {

    std::vector<std::vector<int>> groups_of_products = {
        get_max_products_of_rows(matrices),
        get_max_products_of_columns(matrices),
        get_products_of_primary_diagonals(matrices),
        get_products_of_secondary_diagonals(matrices)
    };

    std::vector<int> products = flatten(groups_of_products);

    auto max_it = std::max_element(products.begin(), products.end());

    if (max_it == products.end()) {
        throw std::runtime_error("Could not compute products");
    }

    return *max_it;
}

int main() {

    try {

        math::matrices::Matrix<int> matrix = read_matrix(PROBLEM_STATEMENT_FILENAME);

        std::cout << "Found matrix of size " 
                << std::to_string(matrix.shape().first) << " x " << std::to_string(matrix.shape().second)
                << " in file " << PROBLEM_STATEMENT_FILENAME << std::endl;

        std::pair<size_t, size_t> submatrix_dimensions = {NUM_ADJACENT_NUMBERS, NUM_ADJACENT_NUMBERS};
        std::vector<math::matrices::Matrix<int>> submatrices = get_submatrices(matrix, submatrix_dimensions);

        std::cout << "Generated " << std::to_string(submatrices.size()) << " submatrices of size "
                << std::to_string(submatrix_dimensions.first) << " x "
                << std::to_string(submatrix_dimensions.second) << std::endl;

        std::cout << std::endl << get_max_product(submatrices) << std::endl;
    }
    catch (const std::ios_base::failure& e) {

        std::cerr << "Failed to read file due to " << e.what() << std::endl;
        return -1;
    }
    catch (const std::runtime_error& e) {

        std::cerr << "Failed to generate submatrices due to " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
