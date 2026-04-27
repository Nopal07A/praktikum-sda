#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Circular Linked List Toko Sembako
struct BarangNode {
    string namaBarang;
    int stok;
    BarangNode* next;

    // Constructor
    BarangNode(string nama, int jumlah) {
        namaBarang = nama;
        stok = jumlah;
        next = nullptr;
    }
};

// Fungsi insert di akhir Circular Linked List untuk membangun data
BarangNode* tambahBarang(BarangNode* head, string nama, int jumlah) {
    BarangNode* newNode = new BarangNode(nama, jumlah);

    // Jika list masih kosong
    if (head == nullptr) {
        newNode->next = newNode; // Node menunjuk ke dirinya sendiri (circular)
        return newNode;
    }
    
    // Traversal ke node terakhir
    BarangNode* temp = head;
    while (temp->next != head) { // Berhenti saat node terakhir (yang menunjuk ke head)
        temp = temp->next;
    }

    temp->next = newNode; // Node terakhir menunjuk ke node baru
    newNode->next = head; // Node baru menunjuk kembali ke head

    return head;
}

// Fungsi untuk menampilkan semua barang dalam Circular Linked List
void tampilkanStokSembako(BarangNode* head) {
    // 1. Base case: jika kosong
    if (head == nullptr) {
        cout << "Gudang kosong." << endl;
        return;
    }

    // 2. Mulai dari head
    BarangNode* temp = head;

    // 3. Traversal menggunakan do-while (agar head ikut diproses)
    do {
        // Cetak data
        cout << "- " << temp->namaBarang << ": " << temp->stok << endl;

        // 4. Pindah ke node berikutnya
        temp = temp->next;

    } while (temp != head); // 5. Berhenti saat kembali ke head
}

int main() {
    BarangNode* head = nullptr;
    
    head = tambahBarang(head, "Beras", 50);
    head = tambahBarang(head, "Minyak Goreng", 30);
    head = tambahBarang(head, "Gula Pasir", 20);
    head = tambahBarang(head, "Tepung Terigu", 15);

    cout << "Daftar Stok Sembako:" << endl;
    tampilkanStokSembako(head); 

    /* Output:
       Daftar Stok Sembako:
       - Beras: 50
       - Minyak Goreng: 30
       - Gula Pasir: 20
       - Tepung Terigu: 15
    */
    
    return 0;
}