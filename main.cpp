#include "graph.h"
#include "matrix_operations.h"
#include "graph.h"
#include "matrix_operations.h"
#include <iostream>
#include <iomanip>

int main() {
   
    IntMatrix D0 = loadMatrixFromFile("graph_D(0).txt");
    IntMatrix D1 = loadMatrixFromFile("graph_D(1).txt");
    IntMatrix Dm1 = loadMatrixFromFile("graph_D(-1).txt");

    IntMatrix C = initializeMatrix(D0, D1, Dm1);

    std::cout << "Initialized matrix C:" << std::endl;
    printIntMatrix(C);

    DoubleMatrix normalizedMatrix = normalize(C);

    std::cout << "Normalized matrix:" << std::endl;
    printDoubleMatrix(normalizedMatrix);

    IntMatrix resultMatrix = matrixMultiply(D0, D1);

    std::cout << "Result of multiplying D0 by D1:" << std::endl;
    printIntMatrix(resultMatrix);

    return 0;
}

