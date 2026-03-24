#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

int n = 0;

void tampilkan(Kereta* arr) {
    cout << "\n=== DATA KERETA ===\n";
    for (int i = 0; i < n; i++) {
        cout << "No: " << (arr + i)->nomor << endl;
        cout << "Nama: " << (arr + i)->nama << endl;
        cout << "Asal: " << (arr + i)->asal << endl;
        cout << "Tujuan: " << (arr + i)->tujuan << endl;
        cout << "Harga: " << (arr + i)->harga << endl;
        cout << "-------------------\n";
    }
}

void tambah(Kereta* arr) {
    cout << "\nMasukkan jumlah data: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nomor: "; cin >> (arr + i)->nomor;
        cin.ignore();
        cout << "Nama: "; getline(cin, (arr + i)->nama);
        cout << "Asal: "; getline(cin, (arr + i)->asal);
        cout << "Tujuan: "; getline(cin, (arr + i)->tujuan);
        cout << "Harga: "; cin >> (arr + i)->harga;
        cin.ignore();
    }
}

void swapKereta(Kereta* a, Kereta* b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(Kereta* arr) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + min)->harga) {
                min = j;
            }
        }
        swapKereta(arr + i, arr + min);
    }
    cout << "\nData berhasil diurutkan berdasarkan harga!\n";
}

void merge(Kereta* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Kereta L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = *(arr + l + i);
    for (int j = 0; j < n2; j++)
        R[j] = *(arr + m + 1 + j);

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].nama < R[j].nama) {
            *(arr + k) = L[i];
            i++;
        } else {
            *(arr + k) = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        *(arr + k) = L[i];
        i++; k++;
    }

    while (j < n2) {
        *(arr + k) = R[j];
        j++; k++;
    }
}

void mergeSort(Kereta* arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void linearSearch(Kereta* arr) {
    string asal, tujuan;
    cout << "\nMasukkan asal: ";
    cin.ignore();
    getline(cin, asal);
    cout << "Masukkan tujuan: ";
    getline(cin, tujuan);

    bool ditemukan = false;

    for (int i = 0; i < n; i++) {
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "\nDitemukan:\n";
            cout << (arr + i)->nama << " - " << (arr + i)->harga << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "Data tidak ditemukan!\n";
    }
}

void jumpSearch(Kereta* arr) {
    int key;
    cout << "\nMasukkan nomor kereta: ";
    cin >> key;

    int step = sqrt(n);
    int prev = 0;

    cout << "\nProses pencarian:\n";

    while ((arr + min(step, n) - 1)->nomor < key) {
        cout << "Cek index " << min(step, n) - 1 << endl;
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            cout << "Tidak ditemukan\n";
            return;
        }
    }

    for (int i = prev; i < min(step, n); i++) {
        cout << "Cek index " << i << endl;
        if ((arr + i)->nomor == key) {
            cout << "\nDitemukan: " << (arr + i)->nama << endl;
            return;
        }
    }

    cout << "Tidak ditemukan\n";
}

int main() {
    Kereta data[100];
    int pilihan;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Linear Search (Rute)\n";
        cout << "4. Jump Search (Nomor)\n";
        cout << "5. Sort Harga (Selection)\n";
        cout << "6. Sort Nama (Merge)\n";
        cout << "7. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambah(data); break;
            case 2: tampilkan(data); break;
            case 3: linearSearch(data); break;
            case 4: jumpSearch(data); break;
            case 5: selectionSort(data); break;
            case 6: mergeSort(data, 0, n - 1); break;
        }

    } while (pilihan != 7);

    return 0;
}