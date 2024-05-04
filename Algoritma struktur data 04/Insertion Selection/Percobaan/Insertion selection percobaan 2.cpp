//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; // Menggunakan namespace std

#define MAX 10
int Data[MAX];

// Fungsi pengurutan penyisipan biner
void BinaryInsertSort() {
    int i, j, l, r, m, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        l = 0;
        r = i - 1;

        // Pencarian biner untuk menemukan posisi yang tepat
        while (l <= r) {
            m = (l + r) / 2;
            if (x < Data[m]) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        // Menggeser elemen untuk menyisipkan elemen yang ditemukan
        for (j = i - 1; j >= l; j--) {
            Data[j + 1] = Data[j];
        }

        Data[l] = x; // Menyisipkan elemen pada posisi yang tepat
    }
}

int main() {
    srand((unsigned int)time(nullptr)); // Inisialisasi seed pengacakan

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() / 1000) + 1; // Membuat angka acak
        cout << "\nData ke " << i << ": " << Data[i];
    }

    // Mengurutkan data dengan pengurutan penyisipan biner
    BinaryInsertSort();

    // Menampilkan data setelah diurutkan
    cout << "\nDATA SETELAH TERURUT";
    for (int i = 0; i < MAX; i++) {
        cout << "\nData ke " << i << ": " << Data[i];
    }

    return 0; // Mengembalikan nilai ke sistem operasi
}

