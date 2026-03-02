#include <iostream>
using namespace std;


// Analisis Kompleksitas Waktu Algoritma FindMin

// 1. min ← A[0]                → c1 (1 kali)
// 2. for i ← 1 to n-1         → c2 (n-1 kali)
// 3.    if A[i] < min         → c3 (n-1 kali)
// 4.       min ← A[i]         → c4 (tergantung kondisi)
// 5. return min               → c5 (1 kali)

// BEST CASE (Tmin(n))
// Terjadi jika elemen pertama sudah minimum.
// Baris 4 tidak pernah dieksekusi.

// Tmin(n) = c1 + c5 + (n-1)c2 + (n-1)c3
// Tmin(n) = an + b
// Tmin(n) = O(n)

// WORST CASE (Tmax(n))
// Terjadi jika array terurut menurun,
// sehingga setiap perbandingan menyebabkan update min.

// Tmax(n) = c1 + c5 + (n-1)c2 + (n-1)c3 + (n-1)c4
// Tmax(n) = an + b
// Tmax(n) = O(n)

int FindMin(int A[], int n, int &indexMin) {
    int min = A[0];
    indexMin = 0;

    for (int i = 1; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
            indexMin = i;
        }
    }
    return min;
}

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    int indexMin;

    int minimum = FindMin(A, n, indexMin);

    cout << "Nilai minimum: " << minimum << endl;
    cout << "Indeks minimum: " << indexMin << endl;

    return 0;
}