#include <iostream>
using namespace std;

void reverseArray(int *arr, int n) {

    int *awal = arr;
    int *akhir = arr + n - 1;

    while(awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;

        awal++;
        akhir--;
    }
}

int main() {

    int arr[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array sebelum dibalik: ";
    for(int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nAlamat memori tiap elemen:" << endl;
    for(int i = 0; i < 7; i++) {
        cout << "Nilai: " << arr[i] 
             << " | Alamat: " << &arr[i] << endl;
    }

    reverseArray(arr, 7);

    cout << "\nArray setelah dibalik: ";
    for(int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}