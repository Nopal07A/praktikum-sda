#include <iostream>
using namespace std;

int main() {

    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};

    int min = A[0];
    int indexMin = 0;

    for(int i = 1; i < 8; i++) {
        if(A[i] < min) {
            min = A[i];
            indexMin = i;
        }
    }

    cout << "Nilai minimum = " << min << endl;
    cout << "Indeks minimum = " << indexMin << endl;

    return 0;
}