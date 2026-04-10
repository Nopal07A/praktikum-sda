#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define MAX 100

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

struct Transaksi {
    string namaPenumpang;
    string namaKereta;
    string asal;
    string tujuan;
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

Transaksi queue[MAX];
int front = -1, rear = -1;

bool isFullQueue() {
    return rear == MAX - 1;
}

bool isEmptyQueue() {
    return front == -1 || front > rear;
}

void enqueue(Kereta* arr) {
    if (isFullQueue()) {
        cout << "Antrian penuh!\n";
        return;
    }

    Transaksi t;
    cout << "Nama Penumpang: ";
    cin.ignore();
    getline(cin, t.namaPenumpang);

    cout << "Pilih nomor kereta: ";
    int no;
    cin >> no;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if ((arr + i)->nomor == no) {
            t.namaKereta = (arr + i)->nama;
            t.asal = (arr + i)->asal;
            t.tujuan = (arr + i)->tujuan;
            found = true;
        }
    }

    if (!found) {
        cout << "Kereta tidak ditemukan!\n";
        return;
    }

    if (isEmptyQueue()) front = 0;
    rear++;

    *(queue + rear) = t;

    cout << "Berhasil masuk antrian!\n";
}

void tampilQueue() {
    if (isEmptyQueue()) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "\n=== ANTRIAN ===\n";
    for (int i = front; i <= rear; i++) {
        cout << (queue + i)->namaPenumpang << " | "
             << (queue + i)->asal << " -> "
             << (queue + i)->tujuan << endl;
    }
}

Transaksi stackT[MAX];
int top = -1;

bool isFullStack() {
    return top == MAX - 1;
}

bool isEmptyStack() {
    return top == -1;
}

void push(Transaksi t) {
    if (isFullStack()) {
        cout << "Riwayat penuh!\n";
        return;
    }

    top++;
    *(stackT + top) = t;

    cout << "Masuk ke riwayat!\n";
}

void pop() {
    if (isEmptyStack()) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "Hapus transaksi: "
         << (stackT + top)->namaPenumpang << endl;

    top--;
}

void tampilStack() {
    if (isEmptyStack()) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "\n=== RIWAYAT ===\n";
    for (int i = top; i >= 0; i--) {
        cout << (stackT + i)->namaPenumpang << " | "
             << (stackT + i)->asal << " -> "
             << (stackT + i)->tujuan << endl;
    }
}

void dequeue() {
    if (isEmptyQueue()) {
        cout << "Antrian kosong!\n";
        return;
    }

    Transaksi t = *(queue + front);

    cout << "\nDiproses:\n";
    cout << t.namaPenumpang << " | "
         << t.asal << " -> " << t.tujuan << endl;

    push(t);

    front++;
}

void peek() {
    cout << "\n=== PEEK ===\n";

    if (!isEmptyQueue()) {
        cout << "Antrian terdepan: "
             << (queue + front)->namaPenumpang << endl;
    } else {
        cout << "Antrian kosong\n";
    }

    if (!isEmptyStack()) {
        cout << "Riwayat terakhir: "
             << (stackT + top)->namaPenumpang << endl;
    } else {
        cout << "Riwayat kosong\n";
    }
}

int main() {
    Kereta data[100];
    int pilihan;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Data Kereta\n";
        cout << "2. Tampilkan Kereta\n";
        cout << "3. Enqueue\n";
        cout << "4. Tampilkan Antrian\n";
        cout << "5. Dequeue\n";
        cout << "6. Tampilkan Riwayat\n";
        cout << "7. Pop Riwayat\n";
        cout << "8. Peek\n";
        cout << "9. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambah(data); break;
            case 2: tampilkan(data); break;
            case 3: enqueue(data); break;
            case 4: tampilQueue(); break;
            case 5: dequeue(); break;
            case 6: tampilStack(); break;
            case 7: pop(); break;
            case 8: peek(); break;
        }

    } while (pilihan != 9);

    return 0;
}