#ifndef MATRIX_H
#define MATRIX_H

#include <array>
#include <cstddef>
#include <functional>
#include <stdexcept>
#include <utility>

namespace math {

namespace matrices {

template <typename T, size_t R, size_t C>
class Matrix {
public:
    Matrix(T initial_value) : data{} {
        static_assert(R >= 1, "Matrix must have at least 1 row");
        static_assert(C >= 1, "Matrix must have at least 1 column");

        for (auto& row : data) {
            for (auto& element : row) {
                element = initial_value;
            }
        }
    }

    T get(size_t row, size_t col) const {
        if (row >= R || col >= C) {
            throw std::out_of_range("Indices out of range");
        }
        return data[row][col];
    }

    void set(size_t row, size_t col, T value) {
        if (row >= R || col >= C) {
            throw std::out_of_range("Indices out of range");
        }
        data[row][col] = value;
    }

    std::pair<size_t, size_t> shape() const {
        return {R, C};
    }

    template<size_t SR, size_t SC>
    Matrix<T, SR, SC> submatrix(size_t start_row, size_t start_col) const {
        if (start_row + SR > R || start_col + SC > C) {
            throw std::out_of_range("Submatrix dimensions exceed matrix dimensions");
        }
        Matrix<T, SR, SC> result{T()};
        for (size_t i = 0; i < SR; ++i) {
            for (size_t j = 0; j < SC; ++j) {
                result.set(i, j, get(start_row + i, start_col + j));
            }
        }
        return result;
    }

    Matrix<T, R, 1> collapse_rows(std::function<T(T, T)> func) {
        Matrix<T, R, 1> result{T()};
        for (size_t j = 0; j < R; ++j) {
            result.set(j, 0, get(j, 0));
        }
        for (size_t i = 1; i < C; ++i) {
            for (size_t j = 0; j < R; ++j) {
                result.set(j, 0, func(result.get(j, 0), get(j, i)));
            }
        }
        return result;
    }

    Matrix<T, 1, C> collapse_columns(std::function<T(T, T)> func) {
        Matrix<T, 1, C> result{T()};
        for (size_t i = 0; i < C; ++i) {
            result.set(0, i, get(0, i));
        }
        for (size_t j = 1; j < R; ++j) {
            for (size_t i = 0; i < C; ++i) {
                result.set(0, i, func(result.get(0, i), get(j, i)));
            }
        }
        return result;
    }

    T collapse_primary_diagonal(std::function<T(T, T)> func) {
        T result = get(0, 0);
        for (size_t i = 1; i < std::min(R, C); ++i) {
            result = func(result, get(i, i));
        }
        return result;
    }

    T collapse_secondary_diagonal(std::function<T(T, T)> func) {
        T result = get(0, C - 1);
        for (size_t i = 1; i < std::min(R, C); ++i) {
            result = func(result, get(i, C - (1 + i)));
        }
        return result;
    }

private:
    std::array<std::array<T, C>, R> data;
};

} // namespace matrices

} // namespace math

#endif // MATRIX_H
