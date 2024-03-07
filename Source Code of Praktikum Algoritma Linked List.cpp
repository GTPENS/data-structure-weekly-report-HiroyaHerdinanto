//Hiroya Herdinanto
//5223600022
//GT11-A

#include <iostream>
#include <cstring>

using namespace std;

// Deklarasi Struktur Simpul
struct Simpul {
    char nama[25];
    int nrp;
    Simpul* next;
};

// Deklarasi Variabel Global
Simpul* ujung = nullptr;
Simpul* tampung = nullptr;

// Fungsi Alokasi Simpul
Simpul* alokasi_simpul() {
    Simpul* baru = new Simpul;
    baru->next = nullptr;
    return baru;
}

// Fungsi Menyisipkan Simpul Ujung
void sisipUjung() {
    Simpul* baru = alokasi_simpul();
    cout << "Nama: ";
    cin >> baru->nama;
    cout << "NRP: ";
    cin >> baru->nrp;
    if (ujung == nullptr) {
        ujung = baru;
        tampung = baru;
    }
    else {
        baru->next = ujung;
        ujung = baru;
    }
}

// Fungsi Membaca/Menampilkan Linked List
void tampilkanList() {
    Simpul* tampil = ujung;
    while (tampil != nullptr) {
        cout << "Nama: " << tampil->nama << ", NRP: " << tampil->nrp << endl;
        tampil = tampil->next;
    }
}

// Fungsi Mencari Simpul Tertentu
void cariSimpul(const char* nama) {
    Simpul* cari = ujung;
    bool ditemukan = false;
    while (cari != nullptr) {
        if (strcmp(cari->nama, nama) == 0) {
            cout << "Data ditemukan: " << cari->nama << ", " << cari->nrp << endl;
            ditemukan = true;
            break;
        }
        cari = cari->next;
    }
    if (!ditemukan) {
        cout << "Data tidak ditemukan." << endl;
    }
}

// Fungsi Menyisipkan Simpul Terakhir
void sisipTerakhir() {
    Simpul* baru = alokasi_simpul();
    cout << "Nama: ";
    cin >> baru->nama;
    cout << "NRP: ";
    cin >> baru->nrp;
    if (ujung == nullptr) {
        ujung = baru;
        tampung = baru;
    }
    else {
        Simpul* cari = ujung;
        while (cari->next != nullptr) {
            cari = cari->next;
        }
        cari->next = baru;
    }
}

// Fungsi Menyisipkan Simpul di Antara Dua Simpul
void sisipDiAntara() {
    char namaSebelum[25];
    char namaSetelah[25];
    Simpul* baru = alokasi_simpul();
    cout << "Nama: ";
    cin >> baru->nama;
    cout << "NRP: ";
    cin >> baru->nrp;
    cout << "Masukkan nama simpul sebelumnya: ";
    cin >> namaSebelum;
    cout << "Masukkan nama simpul setelahnya: ";
    cin >> namaSetelah;

    Simpul* cari = ujung;
    Simpul* simpulSebelum = nullptr;
    bool ditemukan = false;

    while (cari != nullptr && !ditemukan) {
        if (strcmp(cari->nama, namaSebelum) == 0 && cari->next != nullptr && strcmp(cari->next->nama, namaSetelah) == 0) {
            ditemukan = true;
            simpulSebelum = cari;
            break;
        }
        cari = cari->next;
    }

    if (ditemukan) {
        baru->next = simpulSebelum->next;
        simpulSebelum->next = baru;
        cout << "Simpul berhasil disisipkan di antara dua simpul." << endl;
    }
    else {
        cout << "Simpul sebelumnya atau simpul setelahnya tidak ditemukan." << endl;
    }
}

// Fungsi Menghapus Simpul
void hapusSimpul(const char* nama) {
    Simpul* current = ujung;
    Simpul* prev = nullptr;
    bool found = false;

    while (current != nullptr) {
        if (strcmp(current->nama, nama) == 0) {
            found = true;
            if (prev == nullptr) {
                // Jika simpul yang akan dihapus adalah simpul pertama
                ujung = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            cout << "Simpul dengan nama " << nama << " berhasil dihapus." << endl;
            break;
        }
        prev = current;
        current = current->next;
    }

    if (!found) {
        cout << "Simpul dengan nama " << nama << " tidak ditemukan." << endl;
    }
}

int main() {
    int pilihan;
    char nama[25];

    do {
        cout << "\nMenu Operasi Linked List:\n";
        cout << "1. Menyisipkan Simpul Ujung\n";
        cout << "2. Menampilkan Linked List\n";
        cout << "3. Mencari Simpul Tertentu\n";
        cout << "4. Menyisipkan Simpul Terakhir\n";
        cout << "5. Menyisipkan Simpul di Antara Dua Simpul\n";
        cout << "6. Menghapus Simpul\n";
        cout << "7. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            sisipUjung();
            break;
        case 2:
            tampilkanList();
            break;
        case 3:
            cout << "Masukkan nama yang ingin dicari: ";
            cin >> nama;
            cariSimpul(nama);
            break;
        case 4:
            sisipTerakhir();
            break;
        case 5:
            sisipDiAntara();
            break;
        case 6:
            cout << "Masukkan nama yang ingin dihapus: ";
            cin >> nama;
            hapusSimpul(nama);
            break;
        case 7:
            cout << "Terima kasih telah menggunakan program ini.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 7);

    return 0;
}

