#include "MatrixOperations.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> matrix;
    int i, j = 0;

    MatrixOperations::readMatrix(matrix, i, j);
    MatrixOperations::processMatrix(matrix, i, j);
    MatrixOperations::writeMatrix(matrix, i, j);

    return 0;
}