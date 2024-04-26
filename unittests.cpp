#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "matrix_operations.h"

TEST_SUITE("Matrix Multiplication Tests") {
    TEST_CASE("Multiply two 2x2 matrices") {
        IntMatrix A = {{1, 2}, {3, 4}};
        IntMatrix B = {{2, 0}, {1, 2}};

        IntMatrix expected = {{4, 4}, {10, 8}};
        IntMatrix result = matrixMultiply(A, B);

        REQUIRE_EQ(result.size(), expected.size());
        for (size_t i = 0; i < result.size(); i++) {
            CHECK_EQ(result[i].size(), expected[i].size());
            for (size_t j = 0; j < result[i].size(); j++) {
                CHECK_EQ(result[i][j], expected[i][j]);
            }
        }
    }

    TEST_CASE("Multiplying matrix by zero matrix should result in zero matrix") {
        IntMatrix A = {{1, 2}, {3, 4}};
        IntMatrix zeroMatrix = {{0, 0}, {0, 0}};
        IntMatrix expected = {{0, 0}, {0, 0}};

        IntMatrix result = matrixMultiply(A, zeroMatrix);

        REQUIRE_EQ(result.size(), expected.size());
        for (size_t i = 0; i < result.size(); i++) {
            CHECK_EQ(result[i].size(), expected[i].size());
            for (size_t j = 0; j < result[i].size(); j++) {
                CHECK_EQ(result[i][j], expected[i][j]);
            }
        }
    }

    TEST_CASE("Matrix multiplication with incompatible dimensions should warn") {
        IntMatrix A = {{1, 2}, {3, 4}};  
        IntMatrix B = {{2}, {3}, {4}};   

        WARN_THROWS_AS(matrixMultiply(A, B), std::invalid_argument);
    }

    TEST_CASE("Require that multiplying identity matrix does not change the matrix") {
        IntMatrix A = {{1, 2}, {3, 4}};
        IntMatrix identity = {{1, 0}, {0, 1}};
        IntMatrix result = matrixMultiply(A, identity);

        REQUIRE_EQ(result.size(), A.size());
        for (size_t i = 0; i < A.size(); i++) {
            for (size_t j = 0; j < A[i].size(); j++) {
                REQUIRE_EQ(result[i][j], A[i][j]); 
            }
        }
    }
}
