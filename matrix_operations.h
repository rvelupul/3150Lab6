#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <vector>
#include <iostream>
#include <iomanip>

using IntMatrix = std::vector<std::vector<int>>;
using DoubleMatrix = std::vector<std::vector<double>>;

IntMatrix matrixMultiply(const IntMatrix& A, const IntMatrix& B);
IntMatrix initializeMatrix(const IntMatrix& D0, const IntMatrix& D1, const IntMatrix& Dm1);
bool detectNegativeOneEdge(int edgeCost, int n);
bool detectPositiveOneEdge(int edgeCost, int n);
bool detectZeroEdge(int edgeCost, int n);
DoubleMatrix normalize(const IntMatrix& A);
void printIntMatrix(const IntMatrix& matrix);
void printDoubleMatrix(const DoubleMatrix& matrix);

#endif 
