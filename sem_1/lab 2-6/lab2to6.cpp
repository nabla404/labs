#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <limits>
#include <set>
#include <numeric>
#include <cmath>
#include <string>
using namespace std;

vector<long long> mergesort(vector<long long>& a) {
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

    // Recursively sort the left and right halves
    l = mergesort(l);
    r = mergesort(r);

    vector<long long> result;
    result.reserve(ln);
    result.insert(result.end(), l.begin(), l.end());
    result.insert(result.end(), r.begin(), r.end());

    return result;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int getFirstDigit(int number) {
    while (number >= 10) {
        number /= 10;
    }
    return number;
}

int getDigitSum(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

// Структура для хранения числа со свойствами, по которым будем сортировать
struct NumberProperties {
    int number;
    int firstDigit;
    int digitSum;

    NumberProperties(int num) : number(num), firstDigit(getFirstDigit(num)), digitSum(getDigitSum(num)) {}
};

// Функция сравнения для сортировки
bool compare(const NumberProperties &a, const NumberProperties &b) {
    if (a.firstDigit != b.firstDigit) {
        return a.firstDigit < b.firstDigit;
    }
    if (a.digitSum != b.digitSum) {
        return a.digitSum < b.digitSum;
    }
    return a.number < b.number;
}


int main() 
{
    //Написать программу, которая на вход получает 3 целых числа A, B, C – стороны треугольника. Рассчитать площадь треугольника по формуле Герона.

    //lab 2
    // long long A,B,C;
    // cin >> A;
    // cin >> B;
    // cin >> C;
    // long long p = (A+B+C)/2;
    // long long s = sqrt(p*(p-A)*(p-B)*(p-C));
    // cout << s;



    //lab 3
    // unsigned int x; // Входное число
    // int i; // Индекс бита

    // cout << "Введите число x (0 < x < 10^9): ";
    // cin >> x;
    // cout << "Введите индекс бита i (начиная с 0): ";
    // cin >> i;

    // // Устанавливаем i-ый бит в 1
    // x |= (1u << i);

    // cout << "Результат: " << x << endl;



    //lab 4.1
    // int A, B, C;
    // cin >> A >> B >> C;
    // if (A % B == 0) {
    //     if (B > C) 
    //     {
    //         cout << "Результат: " << A / B + C << endl;
    //     } 
    //     else 
    //     {
    //         cout << "Результат: " << A / B - C << endl;
    //     }
    // }
    // else 
    // {
    //     cout << "Результат: " << (A + B) * C << endl;
    // }

    //lab 4.2
    // int N;
    
    // cout << "Введите номер месяца (1 - 12): ";
    // cin >> N;

    // switch (N) {
    //     case 1:
    //         cout << "Январь" << endl;
    //         break;
    //     case 2:
    //         cout << "Февраль" << endl;
    //         break;
    //     case 3:
    //         cout << "Март" << endl;
    //         break;
    //     case 4:
    //         cout << "Апрель" << endl;
    //         break;
    //     case 5:
    //         cout << "Май" << endl;
    //         break;
    //     case 6:
    //         cout << "Июнь" << endl;
    //         break;
    //     case 7:
    //         cout << "Июль" << endl;
    //         break;
    //     case 8:
    //         cout << "Август" << endl;
    //         break;
    //     case 9:
    //         cout << "Сентябрь" << endl;
    //         break;
    //     case 10:
    //         cout << "Октябрь" << endl;
    //         break;
    //     case 11:
    //         cout << "Ноябрь" << endl;
    //         break;
    //     case 12:
    //         cout << "Декабрь" << endl;
    //         break;
    //     default:
    //         cout << "Ошибка: введённое число должно быть от 1 до 12." << endl;
    //         break;
    // }


    //lab 4.3
    // int x;

    // cout << "Enter the value of x (-1 or 1): ";
    // cin >> x;

    // // Проверяем значение переменной x
    // if (x == -1) {
    //     cout << "Negative number" << endl;
    // } else if (x == 1) {
    //     cout << "Positive number" << endl;
    // } else {
    //     cout << "Invalid input, please enter -1 or 1." << endl;
    // }


    //lab 5.1
    // long long N; // количество чисел в последовательности
    // cin >> N;

    // vector<long long> A(N);
    // for(long long x = 1; x <= N; x++) {
    //     A[x-1] = x;
    // }

    // long long product = 1;    // произведение
    // bool found = false;       // флаг, чтобы проверить, найдены ли числа
    // int minNumber = INT_MAX; // наименьшее число
    // int minIndex = -1;       // индекс наименьшего числа

    // for (int i = 0; i < N; ++i) {
    //     int lastDigit = A[i] % 10; // последняя цифра числа
    //     if (lastDigit == 2 || lastDigit == 4) {
    //         product *= A[i];
    //         cout << product << ' ';
    //         found = true;

    //         if (A[i] < minNumber) {
    //             minNumber = A[i];
    //             minIndex = i;
    //         }
    //     }
    // }

    // if (found) {
    //     cout << "product of numbers lasts 2 or 4: " << product << endl;
    //     cout << "min number lasts 2 or 4: " << minNumber << " index: " << minIndex << endl;
    // } else {
    //     cout << "not found" << endl;
    // }

    //lab 5.2
    // long long N;
    // cout << "Enter N < 10^9: ";
    // cin >> N;

    // int max_digit = 0;

    // while (N > 0) {
    //     int last_digit = N % 10;
    //     if (last_digit > max_digit) {
    //         max_digit = last_digit;
    //     }
    //     N /= 10;
    // }

    // cout << max_digit << endl;


    //lab 6.1 	Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). Если в последовательности есть хотя бы одно число, начинающееся цифрой 1, упорядочить последовательность по неубыванию.
    // vector<long long> A(10'000);
    // iota(A.begin(), A.end(), 0);
    // shuffle(A.begin(), A.end(), mt19937{random_device{}()});

    // bool flag = 0;

    // for(int i=0; i<10; i++) cout << A[i] << ' '; // a[0,9]
    // cout << endl;
    // for(int i=0; i<10; i++) cout << A[A.size()-i-1] << ' '; // a[-10,-1]
    // cout << endl;

    // for (int x : A) {
    //     if (to_string(x)[0] == '1') {
    //         flag = true;
    //         break;
    //     }
    // }

    // if(flag)
    // {
    //     auto sA = mergesort(A);

    //     for(int i=0; i<10; i++) cout << sA[i] << ' '; // a[0,9]
    //     cout << endl;
    //     for(int i=1; i<10; i++) cout << sA[sA.size()-i] << ' '; // a[-10,-1]
    // }

        
    //lab 6.2
    // int n;
    // cin >> n;

    // vector<int> numbers(n);
    // cout << "Enter " << n << " numbers:" << endl;
    // for (int i = 0; i < n; ++i) {
    //     cin >> numbers[i];
    // }

    // vector<NumberProperties> properties;
    // for (int num : numbers) {
    //     properties.emplace_back(num);
    // }

    // sort(properties.begin(), properties.end(), compare);

    // cout << "Отсортированные числа:" << endl;
    // for (const auto &str : properties) {
    //     cout << str.number << ' ';
    // }
    // cout << endl;


    //lab 6.3 	Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). Найти строку, сумма элементов которой наиболее близка к 0, и заменить все элементы этой строки числом 0.
    // int n, m;
    // cout << "Enter number of rows (n): ";
    // cin >> n;
    // cout << "Enter number of columns (m): ";
    // cin >> m;

    // vector<vector<int>> matrix(n, vector<int>(m));

    // // Input values into the matrix
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << "Enter value for [" << i+1 << "][" << j+1 << "]: ";
    //         cin >> matrix[i][j];
    //     }
    // }

    // // Output the matrix
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << matrix[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // int closestRow = -1; // Индекс строки с суммой, ближайшей к 0
    // int minDistance = INT_MAX; // Минимальное расстояние от 0

    // // Поиск строки с суммой, ближайшей к 0
    // for (int i = 0; i < n; ++i) {
    //     int sum = 0;
    //     for (int j = 0; j < m; ++j) {
    //         sum += matrix[i][j];
    //     }
        
    //     // Вычисляем абсолютное значение суммы
    //     int distance = abs(sum);
        
    //     // Сравниваем с минимальным расстоянием
    //     if (distance < minDistance) {
    //         minDistance = distance;
    //         closestRow = i; // Сохраняем индекс строки
    //     }
    // }

    // if (closestRow != -1) {
    //     for (int j = 0; j < m; ++j) {
    //         matrix[closestRow][j] = 0;
    //     }
    // }

    // // Output the matrix
    // cout << endl;
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << matrix[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    //lab 6.4
    int j = 5;
    vector<int> A = {2,767,77,777,3};

    for(int i=0;i<j;i++) cout << A[i] << ' ';
    cout << endl;

    int Δ = 0;
    for(int x=0; x<j; ++x)
    {
        int x64 = A[x];
        bool has6=0, has7=0;
        while (x64 >= 1)
        {
            int y = x64%10;
            x64 /= 10;
            if(y == 7) has7 = 1;
            if(y == 6) has6 = 1;
        }

        if (has7 && !has6) ++Δ; 
        else 
        {
            A[x-Δ] = A[x];
            if (isPrime(A[x])) { A.insert(A.begin()+x, A[x]); ++j; ++x; A[x-Δ] = A[x]; }
        }
    }
    j -= Δ;
    A.resize(j);

    for(int i=0;i<j;i++) cout << A[i] << ' ';


    return 0;
}