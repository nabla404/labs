#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int getSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long O10n(int N) { // O(10^n) brute force
    int max_sum = 9 * N + 1;
    vector<int> D(max_sum, 0);

    for (int x = 0; x < pow(10, N); ++x) {
        D[getSum(x)]++;
    }

    long long L_n = 0;
    for (int y = 0; y < max_sum; ++y) {
        L_n += static_cast<long long>(D[y]) * D[y];
    }

    return L_n;
}

long long On2(int n) { // O(n^2) dynamic programming
    int max_sum = 9 * n;
    vector<vector<int>> D(n + 1, vector<int>(max_sum + 1, 0));
    D[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k <= max_sum; ++k) {
            for (int j = 0; j < 10; ++j) {
                if (k - j >= 0) {
                    D[i][k] += D[i - 1][k - j];
                }
            }
        }
    }

    long long L_n = 0;
    for (int k = 0; k <= max_sum; ++k) {
        L_n += static_cast<long long>(D[n][k]) * D[n][k];
    }

    return L_n;
}

long long On(int N) { // O(???)
    int mx_sm = 9 * N;
    vector<int> D(mx_sm + 1, 0);
    D[0] = 1;

    vector<int> incrY(N, 0);
    incrY[0] = 1;
    incrY[1] = 1 - N;
    for (int i = 2; i < N; ++i) {
        incrY[i] = -incrY[i - 1] * N / i + incrY[i - 1];
    }

    vector<int> incrA(N - 2, 0);
    for (int i = 0; i < N - 2; ++i) {
        incrA[i] = N - i - 1;
    }

    int delta = 0;
    for (int i = 1; i <= mx_sm / 2 + 1; ++i) {
        D[i] = D[i - 1] + incrA[0];
        incrA.back() += incrY[(i - delta) / 9];

        delta += (i % 10 == 0);
        for (int j = N - 3; j > 0; --j) {
            incrA[j - 1] += incrA[j];
        }
    }

    for (int j = mx_sm / 2; j <= mx_sm; ++j) {
        D[j] = D[mx_sm - j];
    }

    long long L_n = 0;
    for (int k = 0; k <= mx_sm; ++k) {
        L_n += static_cast<long long>(D[k]) * D[k];
    }

    return L_n;
}

int main() {
    int N = 3;
    cout << O10n(N) << ' ' << On2(N) << ' ' << On(N) << endl;
    // cout << On2(N) << ' ' << On(N) << endl;
    return 0;
}