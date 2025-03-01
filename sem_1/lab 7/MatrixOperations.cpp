#include "MatrixOperations.hpp"
#include <iostream>
#include <numeric>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

namespace MatrixOperations {
    void readMatrix(vector<vector<int>>& matrix, int& i, int& j) {
        cout << "matrix ij: ";
        cin >> i;
        cin >> j;

        matrix.resize(i, vector<int>(j));
        cout << "matrix elements:" << endl;
        for (int x = 0; x < i; ++x) {
            for (int y = 0; y < j; ++y) {
                cin >> matrix[x][y];
            }
        }
    }

    bool isPrime(int number) {
        if (number <= 1) return false;
        for (int x = 2; x <= sqrt(number); ++x) {
            if (number % x == 0) return false;
        }
        return true;
    }

    vector<long long> BogoSort(vector<long long>& a) {
        long long ln = a.size();
        if (ln <= 1) {
            return a;
        }
        
        if (set<long long>(a.begin(), a.end()).size() == 1) {
            return a;
        }
        
        double avg_a = accumulate(a.begin(), a.end(), 0.0) / ln;
        vector<long long> l, r;

        for (long long x : a) {
            if (x < avg_a) {
                l.push_back(x);
            } else {
                r.push_back(x);
            }
        }

        l = BogoSort(l);
        r = BogoSort(r);

        vector<long long> result;
        result.reserve(ln);
        result.insert(result.end(), l.begin(), l.end());
        result.insert(result.end(), r.begin(), r.end());

        return result;
    }

    void processMatrix(vector<vector<int>>& matrix, int& i, int& j) {
        bool hasDuplicateColumn = false;
        bool hasPrimeElement = false;

        // Проверка на наличие одинаковых столбцов
        for (int x = 0; x < i-1; ++x) {
            for (int y = x + 1; y < j; ++y) {
                bool areEqual = true;
                for (int z = 0; z < i; ++z) {
                    if (matrix[z][x] != matrix[z][y]) {
                        areEqual = false;
                        break;
                    }
                }
                if (areEqual) {
                    hasDuplicateColumn = true;
                    break;
                }
            }
            if (hasDuplicateColumn) break;
        }

        // Проверка на наличие простого числа
        for (int x = 0; x < i; ++x) {
            for (int y = 0; y < j; ++y) {
                if (isPrime(abs(matrix[x][y]))) {
                    hasPrimeElement = true;
                    break;
                }
            }
        }

        // Упорядочивание строк по неубыванию суммы модулей элементов
        if (hasDuplicateColumn && hasPrimeElement) {
            sort(matrix.begin(), matrix.end(), [](const vector<int>& a, const vector<int>& b) {
                int sumA = 0, sumB = 0;
                for (int element : a) sumA += abs(element);
                for (int element : b) sumB += abs(element);
                return sumA < sumB;
            });
        }

        cout << hasDuplicateColumn << hasPrimeElement;
    }

    void writeMatrix(const vector<vector<int>>& matrix, int& i, int& j) {
        cout << "Result:" << endl;
        for (int x = 0; x < i; ++x) {
            for (int y = 0; y < j; ++y) {
                cout << matrix[x][y] << " ";
            }
            cout << endl;
        }
    }
}