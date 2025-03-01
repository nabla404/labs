#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

long long O10n(int N) { // O(10^n) brute force
    int max_sum = 9 * N + 1;
    vector<int> D(max_sum, 0);

    for (int x = 0; x < pow(10, N); ++x) {
        D[sumOfDigits(x)]++;
    }

    long long L_n = 0;
    for (int y = 0; y < max_sum; ++y) {
        L_n += D[y] * D[y];
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


int main(){
    // // dop 1
    // // int Q1, P1, Q2, P2, A;
    // // cin >> Q1 >> P1 >> Q2 >> P2 >> A;
    // int Q1 = 1, P1 = 2, Q2 = 3, P2 = 4, A = 10;

    // bool ost = A%Q2 != 0;
    // bool ost_2 = A%Q1 != 0;

    // int cost1 = (A/Q1+ost_2)*P1;
    // int cost2 = A/Q1*P1+( A%Q1 / Q2 + (A%Q1 %Q2 != 0) )*P2;

    // int cost3 = (A/Q2+ost)*P2;
    // int cost4 = A/Q2*P2+( A%Q2 / Q1 + (A%Q2 %Q1 != 0) )*P1;

    // // cout << cost1 << ' ' << cost2 << ' ' << cost3 << ' ' << cost4 << endl;
    // cout << min( min(cost1, cost2), min(cost3, cost4) );


    // dop 2
    int N = 3;
    cout << O10n(N) << ' ' << On2(N) << ' ' << On(N) << endl;
    // cout << On2(N) << ' ' << On(N) << endl;


    // dop 3
    // int j = 5;
    // vector<int> A = {2,767,77,777,3};

    // for(int i=0;i<j;i++) cout << A[i] << ' ';
    // cout << endl;

    // int Δ = 0;
    // for(int x=0; x<j; ++x)
    // {
    //     if (isPrime(A[x])) ++Δ; 
    //     else 
    //     {
    //         A[x-Δ] = A[x];
    //         if (sumOfDigits(A[x]) == 15) 
    //         { 
    //             A.insert(A.begin()+x, A[x]); ++j; ++x; A[x-Δ] = A[x]; 
    //         }
    //     }
    // }
    // j -= Δ;
    // A.resize(j);

    // for(int i=0;i<j;i++) cout << A[i] << ' ';

    int j = 5;
    int* A = new int[j]{ 3, 78, 77, 777 , 3};

    for(int i=0;i<j;i++) cout << A[i] << ' ';
    cout << endl;

    int Δ = 0;
    int count15 = 0;
    for(int x=0; x<j; ++x)
    {
        if (isPrime(A[x])) ++Δ; 
        else 
        {
            A[x-Δ] = A[x];
            if (sumOfDigits(A[x]) == 15) ++count15;
        }
    }
    j += count15-Δ;

    for(int x=j-1; x>=0; --x){
        if (sumOfDigits(A[x]) == 15) { A[x+count15] = A[x]; --count15; }
        A[x+count15] = A[x];
    }

    for(int x=0; x<j; ++x) cout << A[x] << ' ';





    return 0;
}