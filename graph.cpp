#include "graph.h"
#include <fstream>
#include <sstream>

IntMatrix loadMatrixFromFile(const std::string& filepath) {
    std::ifstream file(filepath);
    IntMatrix matrix;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<int> row;
        int value;
        while (iss >> value) {
            row.push_back(value);
        }
        matrix.push_back(row);
    }
    return matrix;
}
