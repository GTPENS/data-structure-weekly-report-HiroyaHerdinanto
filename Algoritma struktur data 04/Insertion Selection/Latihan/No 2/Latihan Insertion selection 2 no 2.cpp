//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 10
int Data[MAX];

int comparisons = 0; // Menghitung jumlah perbandingan
int shifts = 0; // Menghitung jumlah pergeseran

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
            comparisons++; // Menghitung perbandingan
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
            shifts++; // Pergeseran
        }

        Data[l] = x;
        shifts++; // Pergeseran saat penyisipan
    }
}

int main() {
    srand((unsigned int)time(nullptr)); // Inisialisasi seed untuk bilangan acak

    cout << "DATA SEBELUM TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() % 100) + 1; // Bilangan acak
        cout << Data[i] << " ";
    }
    cout << endl;

    BinaryInsertSort(); // Mengurutkan dengan penyisipan biner

    cout << "\nDATA SETELAH TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;

    cout << "Jumlah perbandingan: " << comparisons << endl;
    cout << "Jumlah pergeseran: " << shifts << endl;

    return 0;
}
