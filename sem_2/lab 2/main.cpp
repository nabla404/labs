#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

// factorial
int factorial(int n){
    if (n <= 1) return 1;
    return n*factorial(n-1);
}

void quicksort(int* arr, int low, int high) {
    if (low >= high) return;

    int piv = arr[low + rand() % (high - low + 1)];
    int l = low, r = high;

    while (l <= r) {
        while (arr[l] < piv) l++;
        while (arr[r] > piv) r--;
        if (l <= r) {
            std::swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }

    quicksort(arr, low, r);
    quicksort(arr, l, high);
}

void merge(int* arr, int low, int mid, int high) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    std::vector<int> left(leftSize);
    std::vector<int> right(rightSize);

    for (int i = 0; i < leftSize; i++) left[i] = arr[low + i];
    for (int i = 0; i < rightSize; i++) right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        arr[k++] = left[i++];
    }

    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

void mergesort(int* arr, int low, int high) {
    if (low >= high) return; // Base case

    int mid = low + (high - low) / 2;

    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// 3
const int N = 15;
const int M = 20;
void print_board(char board[][M], int N, int M){
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void randomize_board(char board[][M], int N, int M){
    const char symbols[2] = {'.','#'};
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            board[i][j] = symbols[rand() % 2];
        }
    }
}

void step_calc(int steps[][M], char board[][M], int N, int M, int i, int j, int depth){
    if (board[i][j] == 'E') return;
    if (j - 1 >= 0 && steps[i][j-1] > depth + 1 && board[i][j-1] != '#') {steps[i][j-1] = depth + 1; step_calc(steps, board, N, M, i, j-1, depth + 1);}
    if (j + 1 < M && steps[i][j+1] > depth + 1 && board[i][j+1] != '#') {steps[i][j+1] = depth + 1; step_calc(steps, board, N, M, i, j+1, depth + 1);}
    if (i-1 >= 0) {
        if (steps[i-1][j] > depth + 1 && board[i-1][j] != '#') {steps[i-1][j] = depth + 1; step_calc(steps, board, N, M, i-1, j, depth + 1);}
        if (j - 1 >= 0 && board[i-1][j-1] != '#' && steps[i-1][j-1] > depth + 1) {steps[i-1][j-1] = depth + 1; step_calc(steps, board, N, M, i-1, j-1, depth + 1);}
        if (j + 1 < M && board[i-1][j+1] != '#' && steps[i-1][j+1] > depth + 1) {steps[i-1][j+1] = depth + 1; step_calc(steps, board, N, M, i-1, j+1, depth + 1);}
    }
    if (i+1 < N) {
        if (steps[i+1][j] > depth + 1 && board[i+1][j] != '#') {steps[i+1][j] = depth + 1; step_calc(steps, board, N, M, i+1, j, depth + 1);}
        if (j - 1 >= 0 && board[i+1][j-1] != '#' && steps[i+1][j-1] > depth + 1) {steps[i+1][j-1] = depth + 1; step_calc(steps, board, N, M, i+1, j-1, depth + 1);}
        if (j + 1 < M && board[i+1][j+1] != '#' && steps[i+1][j+1] > depth + 1) {steps[i+1][j+1] = depth + 1; step_calc(steps, board, N, M, i+1, j+1, depth + 1);}
    }
}

// int arr[10'000'000];
int main(){
    srand(time(0));
    //std::cout << factorial(30);

    // 2
    // int n = sizeof(arr) / sizeof(arr[0]);
    // for (int i = 0; i < n; i++) arr[i] = 1 + rand() % 10000;
    // printArray(arr, n);

    // quicksort(arr, 0, n - 1);
    // printArray(arr, n);

    // 3
    int steps[N][M]; for (int i = 0; i < N; i++) {for (int j=0; j < M; j++) steps[i][j] = INT_MAX / 2;}
    char board[N][M] = {
    {'S', '.', '.', '.', '.'}, 
    {'.', '.', '.', '.', '.'}, 
    {'.', '.', '.', '.', '.'}, 
    {'.', '.', '.', '.', '.'}, 
    {'.', '.', '.', '.', 'E'}, 
    };

    // char board[N][M] = {
    // {'.', '#', '.', '#', '#'}, 
    // {'.', '#', '.', '#', 'E'}, 
    // {'#', '.', '#', '#', '#'}, 
    // {'.', '#', '#', '.', '.'}, 
    // {'.', '#', 'S', '#', '#'}, 
    // };
    // int S[2] = {4, 2};
    // int E[2] = {1, 4};

    // int S[2] = {0, 0};
    // int E[2] = {N-1, M-1};
    randomize_board(board, N, M);
    int S[2] = {rand() % N,rand() % M};
    int E[2] = {rand() % N,rand() % M};
    while (S[0] == E[0] && S[1] == E[1]) {E[0] = rand() % N, E[1]  = rand() % M;}
    board[S[0]][S[1]] = 'S';
    board[E[0]][E[1]] = 'E';
    steps[S[0]][S[1]] = 0;
    print_board(board, N, M);

    step_calc(steps, board, N, M, S[0], S[1], 0);
    std::cout << "steps " << (steps[E[0]][E[1]] == INT_MAX/2 ? -1 : steps[E[0]][E[1]]) << std::endl;
    // for (int i=0; i<N; i++){
    //     for (int j=0; j<M; j++){
    //         std::cout << steps[i][j] << ' ';
    //     }
    //     std::cout << std::endl;
    // }


    return 0;
}