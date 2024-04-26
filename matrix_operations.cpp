#include "matrix_operations.h"
#include <cmath>
#include <iostream>
#include <iomanip>

IntMatrix matrixMultiply(const IntMatrix& A, const IntMatrix& B) {
    int n = A.size();
    IntMatrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

IntMatrix initializeMatrix(const IntMatrix& D0, const IntMatrix& D1, const IntMatrix& Dm1) {
    int n = D0.size();
    int temp = 3 * (n + 1);
    IntMatrix C(n, std::vector<int>(n, 0));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += std::pow(temp, D0[i][k] + Dm1[k][j] + 1) +
                           std::pow(temp, Dm1[i][k] + D0[k][j] + 1);
                C[i][j] += std::pow(temp, Dm1[i][k] + D1[k][j] + 1) +
                           std::pow(temp, D1[i][k] + Dm1[k][j] + 1);
                C[i][j] += std::pow(temp, D0[i][k] + D1[k][j] + 1) +
                           std::pow(temp, D1[i][k] + D0[k][j] + 1);
            }
        }
    }
    return C;
}

bool detectNegativeOneEdge(int edgeCost, int n) {
    int temp = 3 * (n + 1);
    double check = temp * (edgeCost % temp) / static_cast<double>(temp);
    return (check >= 1 && check <= 2 * n);
}


bool detectPositiveOneEdge(int edgeCost, int n) {
    int temp = 3 * (n + 1);
    int check = edgeCost / temp;
    return (check >= 1 && check <= 2 * n);
}


bool detectZeroEdge(int edgeCost, int n) {
    int temp = 3 * (n + 1);
    int check = edgeCost % temp;
    return (check > 0 && check <= 3 * n);
}

DoubleMatrix normalize(const IntMatrix& A) {
    int n = A.size();
    double temp = 3 * (n + 1);
    DoubleMatrix normMatrix(n, std::vector<double>(n, 0.0));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int edgeCost = A[i][j];


            if (detectZeroEdge(edgeCost, n)) {
                normMatrix[i][j] = 1.0;
            } else if (detectPositiveOneEdge(edgeCost, n)) {
                normMatrix[i][j] = temp;
            } else if (detectNegativeOneEdge(edgeCost, n)) {
                normMatrix[i][j] = 1.0 / temp;
            } else {
                normMatrix[i][j] = 0.0;
            }
        }
    }
    return normMatrix;
}

void printIntMatrix(const IntMatrix& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << std::setw(5) << val;
        }
        std::cout << std::endl;
    }
}

void printDoubleMatrix(const DoubleMatrix& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            std::cout << std::setw(12) << std::setprecision(4) << val;
        }
        std::cout << std::endl;
    }
}
