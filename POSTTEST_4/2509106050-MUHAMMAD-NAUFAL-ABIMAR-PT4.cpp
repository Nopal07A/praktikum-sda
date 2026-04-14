#include <iostream>
#include <string>
using namespace std;

struct Transaksi {
    string namaPenumpang;
    string namaKereta;
    string asal;
    string tujuan;
    Transaksi* next;
};

Transaksi *frontQ = NULL, *rearQ = NULL;
Transaksi* topS = NULL;

bool isEmptyQueue() {
    return frontQ == NULL;
}

bool isEmptyStack() {
    return topS == NULL;
}

void enqueue() {
    Transaksi* baru = new Transaksi;

    cin.ignore();
    cout << "Nama Penumpang: ";
    getline(cin, baru->namaPenumpang);

    cout << "Nama Kereta: ";
    getline(cin, baru->namaKereta);

    cout << "Asal: ";
    getline(cin, baru->asal);

    cout << "Tujuan: ";
    getline(cin, baru->tujuan);

    baru->next = NULL;

    if (isEmptyQueue()) {
        frontQ = rearQ = baru;
    } else {
        rearQ->next = baru;
        rearQ = baru;
    }

    cout << "Berhasil enqueue!\n";
}

void push(Transaksi* data) {
    Transaksi* baru = new Transaksi;

    *baru = *data;
    baru->next = topS;
    topS = baru;

    cout << "Masuk ke riwayat!\n";
}

void dequeue() {
    if (isEmptyQueue()) {
        cout << "Antrian kosong!\n";
        return;
    }

    Transaksi* hapus = frontQ;

    cout << "Diproses: " << hapus->namaPenumpang << endl;

    push(hapus);

    frontQ = frontQ->next;
    delete hapus;

    if (frontQ == NULL) {
        rearQ = NULL;
    }
}

void pop() {
    if (isEmptyStack()) {
        cout << "Riwayat kosong!\n";
        return;
    }

    Transaksi* hapus = topS;

    cout << "Hapus riwayat: " << hapus->namaPenumpang << endl;

    topS = topS->next;
    delete hapus;
}

void peek() {
    cout << "\n=== PEEK ===\n";

    if (!isEmptyQueue()) {
        cout << "Depan Antrian: " << frontQ->namaPenumpang << endl;
    } else {
        cout << "Antrian kosong\n";
    }

    if (!isEmptyStack()) {
        cout << "Top Riwayat: " << topS->namaPenumpang << endl;
    } else {
        cout << "Riwayat kosong\n";
    }
}

void tampilQueue() {
    if (isEmptyQueue()) {
        cout << "Antrian kosong!\n";
        return;
    }

    Transaksi* temp = frontQ;

    cout << "\n=== ANTRIAN ===\n";
    while (temp != NULL) {
        cout << temp->namaPenumpang << " | "
             << temp->asal << " -> "
             << temp->tujuan << endl;
        temp = temp->next;
    }
}

void tampilStack() {
    if (isEmptyStack()) {
        cout << "Riwayat kosong!\n";
        return;
    }

    Transaksi* temp = topS;

    cout << "\n=== RIWAYAT ===\n";
    while (temp != NULL) {
        cout << temp->namaPenumpang << " | "
             << temp->asal << " -> "
             << temp->tujuan << endl;
        temp = temp->next;
    }
}

int main() {
    int pilih;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Tampil Antrian\n";
        cout << "4. Tampil Riwayat\n";
        cout << "5. Pop Riwayat\n";
        cout << "6. Peek\n";
        cout << "7. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: tampilQueue(); break;
            case 4: tampilStack(); break;
            case 5: pop(); break;
            case 6: peek(); break;
        }

    } while (pilih != 7);

    return 0;
}