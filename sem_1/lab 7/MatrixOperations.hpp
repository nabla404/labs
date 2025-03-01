#ifndef MATRIXOPERATIONS_HPP
#define MATRIXOPERATIONS_HPP

#include <vector>

namespace MatrixOperations {
    void readMatrix(std::vector<std::vector<int>>& matrix, int& i, int& j);
    void processMatrix(std::vector<std::vector<int>>& matrix, int& i, int& j);
    void writeMatrix(const std::vector<std::vector<int>>& matrix, int& i, int& j);
    bool isPrime(int number);
}

#endif