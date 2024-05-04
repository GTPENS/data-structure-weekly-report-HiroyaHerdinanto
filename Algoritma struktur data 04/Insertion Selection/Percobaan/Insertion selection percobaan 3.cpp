//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; // Menggunakan namespace std

#define MAX 10
int Data[MAX];

// Fungsi pertukaran bilangan
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi pengurutan seleksi
void SelectionSort() {
    int i, j, k;
    for (i = 0; i < MAX - 1; i++) {
        k = i;
        // Cari indeks elemen terkecil
        for (j = i + 1; j < MAX; j++) {
            if (Data[k] > Data[j]) {
                k = j;
            }
        }
        // Tukar elemen terkecil dengan elemen pada indeks i
        Tukar(&Data[i], &Data[k]);
    }
}

int main() {
    srand((unsigned int)time(nullptr)); // Inisialisasi seed untuk bilangan acak

    cout << "DATA SEBELUM TERURUT";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() / 1000) + 1; // Membangkitkan bilangan acak
        cout << "\nData ke " << i << ": " << Data[i];
    }

    // Mengurutkan data dengan pengurutan seleksi
    SelectionSort();

    cout << "\nDATA SETELAH TERURUT";
    for (int i = 0; i < MAX; i++) {
        cout << "\nData ke " << i << ": " << Data[i];
    }

    return 0; // Mengembalikan nilai ke sistem operasi
}
