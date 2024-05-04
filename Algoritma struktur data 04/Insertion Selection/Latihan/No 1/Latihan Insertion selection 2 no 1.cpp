//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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

        // Menggeser elemen untuk menyisipkan elemen pada posisi yang benar
        for (j = i - 1; j >= l; j--) {
            Data[j + 1] = Data[j];
        }

        Data[l] = x; // Menyisipkan elemen

        // Menampilkan perubahan pada setiap iterasi
        cout << "Iterasi " << i << ": ";
        for (int k = 0; k < MAX; k++) {
            cout << Data[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand((unsigned int)time(nullptr)); // Inisialisasi seed pengacakan

    cout << "DATA SEBELUM TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() % 100) + 1; // Membangkitkan bilangan acak
        cout << Data[i] << " ";
    }
    cout << endl;

    BinaryInsertSort(); // Pengurutan dengan penyisipan biner

    return 0;
}
