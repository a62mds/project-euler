#include "doctest.h"

#include "Matrix.h"


TEST_CASE("Test method math::matrices::Matrix::get") {
    math::matrices::Matrix<int, 1ul, 1ul> m(0);

    SUBCASE("Test element can be retrieved when row and col in range") {
        CHECK_EQ(m.get(0, 0), 0);
    }

    SUBCASE("Test std::out_of_range thrown when row out of range") {
        CHECK_THROWS_AS(m.get(1, 0), std::out_of_range);
    }

    SUBCASE("Test std::out_of_range thrown when row negative") {
        CHECK_THROWS_AS(m.get(-1, 0), std::out_of_range);
    }

    SUBCASE("Test std::out_of_range thrown when col out of range") {
        CHECK_THROWS_AS(m.get(0, 1), std::out_of_range);
    }

    SUBCASE("Test std::out_of_range thrown when col negative") {
        CHECK_THROWS_AS(m.get(0, -1), std::out_of_range);
    }

    SUBCASE("Test std::out_of_range thrown when row and col out of range") {
        CHECK_THROWS_AS(m.get(1, 1), std::out_of_range);
    }
}

TEST_CASE("Test method math::matrices::Matrix::set") {
    math::matrices::Matrix<int, 3ul, 3ul> m(0);

    for (size_t row=0; row < 3; row++) {
        for (size_t col=0; col < 3; col++) {
            CHECK_EQ(m.get(row, col), 0);
        }
    }

    SUBCASE("Test element can be set when row and col in range") {
        m.set(0, 0, 1);
        m.set(0, 1, 2);
        m.set(0, 2, 3);
        m.set(1, 0, 4);
        m.set(1, 1, 5);
        m.set(1, 2, 6);
        m.set(2, 0, 7);
        m.set(2, 1, 8);
        m.set(2, 2, 9);

        CHECK_EQ(m.get(0, 0), 1);
        CHECK_EQ(m.get(0, 1), 2);
        CHECK_EQ(m.get(0, 2), 3);
        CHECK_EQ(m.get(1, 0), 4);
        CHECK_EQ(m.get(1, 1), 5);
        CHECK_EQ(m.get(1, 2), 6);
        CHECK_EQ(m.get(2, 0), 7);
        CHECK_EQ(m.get(2, 1), 8);
        CHECK_EQ(m.get(2, 2), 9);
    }

    SUBCASE("Test std::out_of_range thrown when row out of range") {
        CHECK_THROWS_AS(m.set(3, 0, 0), std::out_of_range);
    }

    SUBCASE("Test std::out_of_range thrown when row negative") {
        CHECK_THROWS_AS(m.set(-1, 0, 0), std::out_of_range);
    }

    SUBCASE("Test std::out_of_range thrown when col out of range") {
        CHECK_THROWS_AS(m.set(0, 3, 0), std::out_of_range);
    }

    SUBCASE("Test std::out_of_range thrown when row negative") {
        CHECK_THROWS_AS(m.set(0, -1, 0), std::out_of_range);
    }
}

TEST_CASE("Test math::matrices::Matrix::shape method") {
    math::matrices::Matrix<double, 3, 4> m(0);

    CHECK_EQ(m.shape().first, 3);
    CHECK_EQ(m.shape().second, 4);
}

TEST_CASE("Test math::matrices::Matrix::submatrix method") {
    math::matrices::Matrix<double, 10, 10> m(0.0);

    double value = 1.0;
    for (size_t row=0; row < 10; ++row) {
        for (size_t col=0; col < 10; ++col) {
            m.set(row, col, value);
            value += 1.0;
        }
    }

    SUBCASE("Test get element in first row and first column as 1 x 1 matrix") {
        math::matrices::Matrix<double, 1, 1> sm = m.submatrix<1, 1>(0, 0);

        CHECK_EQ(sm.shape().first, 1);
        CHECK_EQ(sm.shape().second, 1);
        CHECK_EQ(sm.get(0, 0), 1.0);
    }

    SUBCASE("Test get element in middle of matrix as 1 x 1 matrix") {
        math::matrices::Matrix<double, 1, 1> sm = m.submatrix<1, 1>(4, 4);

        CHECK_EQ(sm.shape().first, 1);
        CHECK_EQ(sm.shape().second, 1);
        CHECK_EQ(sm.get(0, 0), 45.0);
    }

    SUBCASE("Test get element in last row and last column as 1 x 1 matrix") {
        math::matrices::Matrix<double, 1, 1> sm = m.submatrix<1, 1>(9, 9);

        CHECK_EQ(sm.shape().first, 1);
        CHECK_EQ(sm.shape().second, 1);
        CHECK_EQ(sm.get(0, 0), 100.0);
    }

    SUBCASE("Test get 2 x 2 submatrix from top left corner") {
        math::matrices::Matrix<double, 2, 2> sm = m.submatrix<2, 2>(0, 0);

        CHECK_EQ(sm.shape().first, 2);
        CHECK_EQ(sm.shape().second, 2);
        CHECK_EQ(sm.get(0, 0), 1.0);
        CHECK_EQ(sm.get(0, 1), 2.0);
        CHECK_EQ(sm.get(1, 0), 11.0);
        CHECK_EQ(sm.get(1, 1), 12.0);
    }

    SUBCASE("Test get 3 x 3 submatrix from bottom right corner") {
        math::matrices::Matrix<double, 3, 3> sm = m.submatrix<3, 3>(7, 7);

        CHECK_EQ(sm.shape().first, 3);
        CHECK_EQ(sm.shape().second, 3);
        CHECK_EQ(sm.get(0, 0), 78.0);
        CHECK_EQ(sm.get(0, 1), 79.0);
        CHECK_EQ(sm.get(0, 2), 80.0);
        CHECK_EQ(sm.get(1, 0), 88.0);
        CHECK_EQ(sm.get(1, 1), 89.0);
        CHECK_EQ(sm.get(1, 2), 90.0);
        CHECK_EQ(sm.get(2, 0), 98.0);
        CHECK_EQ(sm.get(2, 1), 99.0);
        CHECK_EQ(sm.get(2, 2), 100.0);
    }
}

TEST_CASE("Test math::matrices::Matrix::collapse_rows method") {
    math::matrices::Matrix<int, 3, 3> m(0);
    m.set(0, 0, 1);
    m.set(0, 1, 2);
    m.set(0, 2, 3);
    m.set(1, 0, 4);
    m.set(1, 1, 5);
    m.set(1, 2, 6);
    m.set(2, 0, 7);
    m.set(2, 1, 8);
    m.set(2, 2, 9);

    SUBCASE("Test with addition function") {
        auto add_func = [](int a, int b) { return a + b; };

        auto result = m.collapse_rows(add_func);

        CHECK_EQ(result.shape().first, 3);
        CHECK_EQ(result.shape().second, 1);
        CHECK_EQ(result.get(0, 0), 6);
        CHECK_EQ(result.get(1, 0), 15);
        CHECK_EQ(result.get(2, 0), 24);
    }

    SUBCASE("Test with multiplication function") {
        auto mult_func = [](int a, int b) { return a * b; };

        auto result = m.collapse_rows(mult_func);

        CHECK_EQ(result.shape().first, 3);
        CHECK_EQ(result.shape().second, 1);
        CHECK_EQ(result.get(0, 0), 6);
        CHECK_EQ(result.get(1, 0), 120);
        CHECK_EQ(result.get(2, 0), 504);
    }
}

TEST_CASE("Test math::matrices::Matrix::collapse_columns method") {
    math::matrices::Matrix<int, 3, 3> m(0);
    m.set(0, 0, 1);
    m.set(0, 1, 2);
    m.set(0, 2, 3);
    m.set(1, 0, 4);
    m.set(1, 1, 5);
    m.set(1, 2, 6);
    m.set(2, 0, 7);
    m.set(2, 1, 8);
    m.set(2, 2, 9);

    SUBCASE("Test with addition function") {
        auto add_func = [](int a, int b) { return a + b; };

        auto result = m.collapse_columns(add_func);

        CHECK_EQ(result.shape().first, 1);
        CHECK_EQ(result.shape().second, 3);
        CHECK_EQ(result.get(0, 0), 12);
        CHECK_EQ(result.get(0, 1), 15);
        CHECK_EQ(result.get(0, 2), 18);
    }

    SUBCASE("Test with multiplication function") {
        auto mult_func = [](int a, int b) { return a * b; };

        auto result = m.collapse_columns(mult_func);

        CHECK_EQ(result.shape().first, 1);
        CHECK_EQ(result.shape().second, 3);
        CHECK_EQ(result.get(0, 0), 28);
        CHECK_EQ(result.get(0, 1), 80);
        CHECK_EQ(result.get(0, 2), 162);
    }
}

TEST_CASE("Test math::matrices::Matrix::collapse_primary_diagonal method") {
    math::matrices::Matrix<int, 2, 3> m1(0);
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(0, 2, 3);
    m1.set(1, 0, 4);
    m1.set(1, 1, 5);
    m1.set(1, 2, 6);

    math::matrices::Matrix<int, 3, 2> m2(0);
    m2.set(0, 0, 1);
    m2.set(0, 1, 2);
    m2.set(1, 0, 3);
    m2.set(1, 1, 4);
    m2.set(2, 0, 5);
    m2.set(2, 1, 6);

    math::matrices::Matrix<int, 3, 3> m3(0);
    m3.set(0, 0, 1);
    m3.set(0, 1, 2);
    m3.set(0, 2, 3);
    m3.set(1, 0, 4);
    m3.set(1, 1, 5);
    m3.set(1, 2, 6);
    m3.set(2, 0, 7);
    m3.set(2, 1, 8);
    m3.set(2, 2, 9);

    SUBCASE("Test with addition function when num rows > num cols") {
        auto add_func = [](int a, int b) { return a + b; };

        auto result = m1.collapse_primary_diagonal(add_func);

        CHECK_EQ(result, 6);
    }

    SUBCASE("Test with addition function when num rows < num cols") {
        auto add_func = [](int a, int b) { return a + b; };

        auto result = m2.collapse_primary_diagonal(add_func);

        CHECK_EQ(result, 5);
    }

    SUBCASE("Test with addition function when num rows == num cols") {
        auto add_func = [](int a, int b) { return a + b; };

        auto result = m3.collapse_primary_diagonal(add_func);

        CHECK_EQ(result, 15);
    }

    SUBCASE("Test with multiplication function when num rows > num cols") {
        auto prod_func = [](int a, int b) { return a * b; };

        auto result = m1.collapse_primary_diagonal(prod_func);

        CHECK_EQ(result, 5);
    }

    SUBCASE("Test with multiplication function when num rows < num cols") {
        auto prod_func = [](int a, int b) { return a * b; };

        auto result = m2.collapse_primary_diagonal(prod_func);

        CHECK_EQ(result, 4);
    }

    SUBCASE("Test with multiplication function when num rows == num cols") {
        auto prod_func = [](int a, int b) { return a * b; };

        auto result = m3.collapse_primary_diagonal(prod_func);

        CHECK_EQ(result, 45);
    }
}

TEST_CASE("Test math::matrices::Matrix::collapse_secondary_diagonal method") {
    math::matrices::Matrix<int, 2, 3> m1(0);
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(0, 2, 3);
    m1.set(1, 0, 4);
    m1.set(1, 1, 5);
    m1.set(1, 2, 6);

    math::matrices::Matrix<int, 3, 2> m2(0);
    m2.set(0, 0, 1);
    m2.set(0, 1, 2);
    m2.set(1, 0, 3);
    m2.set(1, 1, 4);
    m2.set(2, 0, 5);
    m2.set(2, 1, 6);

    math::matrices::Matrix<int, 3, 3> m3(0);
    m3.set(0, 0, 1);
    m3.set(0, 1, 2);
    m3.set(0, 2, 3);
    m3.set(1, 0, 4);
    m3.set(1, 1, 5);
    m3.set(1, 2, 6);
    m3.set(2, 0, 7);
    m3.set(2, 1, 8);
    m3.set(2, 2, 9);

    SUBCASE("Test with addition function when num rows > num cols") {
        auto add_func = [](int a, int b) { return a + b; };

        auto result = m1.collapse_secondary_diagonal(add_func);

        CHECK_EQ(result, 8);
    }

    SUBCASE("Test with addition function when num rows < num cols") {
        auto add_func = [](int a, int b) { return a + b; };

        auto result = m2.collapse_secondary_diagonal(add_func);

        CHECK_EQ(result, 5);
    }

    SUBCASE("Test with addition function when num rows == num cols") {
        auto add_func = [](int a, int b) { return a + b; };

        auto result = m3.collapse_secondary_diagonal(add_func);

        CHECK_EQ(result, 15);
    }

    SUBCASE("Test with multiplication function when num rows > num cols") {
        auto prod_func = [](int a, int b) { return a * b; };

        auto result = m1.collapse_secondary_diagonal(prod_func);

        CHECK_EQ(result, 15);
    }

    SUBCASE("Test with multiplication function when num rows < num cols") {
        auto prod_func = [](int a, int b) { return a * b; };

        auto result = m2.collapse_secondary_diagonal(prod_func);

        CHECK_EQ(result, 6);
    }

    SUBCASE("Test with multiplication function when num rows == num cols") {
        auto prod_func = [](int a, int b) { return a * b; };

        auto result = m3.collapse_secondary_diagonal(prod_func);

        CHECK_EQ(result, 105);
    }
}
