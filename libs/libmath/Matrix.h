#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <functional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace math {

namespace matrices {

template <typename T>
class Matrix {
public:
    Matrix(size_t num_rows, size_t num_cols) : num_rows(num_rows), num_cols(num_cols) {

        validate_dimensions(num_rows, num_cols);

        data.resize(num_rows, std::vector<T>(num_cols));
    }

    Matrix(size_t num_rows, size_t num_cols, const T& initial_value) : num_rows(num_rows), num_cols(num_cols) {
        
        validate_dimensions(num_rows, num_cols);

        data.resize(num_rows, std::vector<T>(num_cols, initial_value));
    }

    Matrix(const std::vector<std::vector<T>>& matrix_rows) : data(matrix_rows) {
        num_rows = matrix_rows.size();
        if (num_rows < 1) {
            throw std::invalid_argument("Matrix must have at least 1 row");
        }

        num_cols = matrix_rows[0].size();
        if (num_cols < 1) {
            throw std::invalid_argument("Matrix must have at least 1 column");
        }
        for (auto& row : matrix_rows) {
            if (row.size() != num_cols) {
                throw std::invalid_argument("Rows have inconsistent sizes");
            }
        }
    }

    T get(size_t row, size_t col) const {
        validate_indices(row, col);

        return data[row][col];
    }

    void set(size_t row, size_t col, T value) {
        validate_indices(row, col);

        data[row][col] = value;
    }

    std::pair<size_t, size_t> shape() const {
        return {num_rows, num_cols};
    }

    Matrix<T> submatrix(size_t start_row, size_t start_col, size_t num_rows, size_t num_cols) const {
        validate_indices(start_row + num_rows - 1, start_col + num_cols - 1);

        Matrix<T> result{num_rows, num_cols, T()};
        for (size_t row_index = 0; row_index < num_rows; ++row_index) {
            for (size_t col_index = 0; col_index < num_cols; ++col_index) {
                result.set(row_index, col_index, get(start_row + row_index, start_col + col_index));
            }
        }
        return result;
    }

    Matrix<T> collapse_rows(std::function<T(T, T)> func) const {
        Matrix<T> result{num_rows, 1ul, T()};
        for (size_t row_index = 0; row_index < num_rows; ++row_index) {
            result.set(row_index, 0, get(row_index, 0));
        }
        for (size_t col_index = 1; col_index < num_cols; ++col_index) {
            for (size_t row_index = 0; row_index < num_rows; ++row_index) {
                result.set(row_index, 0, func(result.get(row_index, 0), get(row_index, col_index)));
            }
        }
        return result;
    }

    Matrix<T> collapse_columns(std::function<T(T, T)> func) const {
        Matrix<T> result{1ul, num_cols, T()};
        for (size_t col_index = 0; col_index < num_cols; ++col_index) {
            result.set(0, col_index, get(0, col_index));
        }
        for (size_t row_index = 1; row_index < num_rows; ++row_index) {
            for (size_t col_index = 0; col_index < num_cols; ++col_index) {
                result.set(0, col_index, func(result.get(0, col_index), get(row_index, col_index)));
            }
        }
        return result;
    }

    T collapse_primary_diagonal(std::function<T(T, T)> func) const {
        T result = get(0, 0);
        for (size_t index = 1; index < std::min(num_rows, num_cols); ++index) {
            result = func(result, get(index, index));
        }

        return result;
    }

    T collapse_secondary_diagonal(std::function<T(T, T)> func) const {
        T result = get(0, num_cols - 1);
        for (size_t index = 1; index < std::min(num_rows, num_cols); ++index) {
            result = func(result, get(index, num_cols - (1 + index)));
        }

        return result;
    }

private:
    void validate_dimensions(size_t num_rows, size_t num_cols) const {
        if (num_rows < 1) {
            throw std::invalid_argument("Matrix must have at least 1 row");
        }
        if (num_cols < 1) {
            throw std::invalid_argument("Matrix must have at least 1 column");
        }
    }

    void validate_indices(size_t row, size_t col) const {
        if (row >= num_rows) {
            throw std::out_of_range("Row index out of range: " + std::to_string(row) + " >= " + std::to_string(num_rows));
        }
        if (col >= num_cols) {
            throw std::out_of_range("Column index out of range: " + std::to_string(col) + " >= " + std::to_string(num_cols));
        }
    }

    size_t num_rows;
    size_t num_cols;
    std::vector<std::vector<T>> data;
};

} // namespace matrices

} // namespace math

#endif // MATRIX_H
