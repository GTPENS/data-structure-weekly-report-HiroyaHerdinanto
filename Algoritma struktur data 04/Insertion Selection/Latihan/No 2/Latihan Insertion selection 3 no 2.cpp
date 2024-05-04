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

// Fungsi pertukaran bilangan
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    shifts++; // Pergeseran terjadi saat pertukaran
}

// Fungsi pengurutan seleksi
void SelectionSort() {
    int i, j, k;
    for (i = 0; i < MAX - 1; i++) {
        k = i;
        // Cari elemen terkecil
        for (j = i + 1; j < MAX; j++) {
            comparisons++; // Menghitung perbandingan
            if (Data[k] > Data[j]) {
                k = j;
            }
        }

        // Tukar elemen terkecil dengan elemen pada indeks i
        if (k != i) {
            Tukar(&Data[i], &Data[k]);
        }
    }
}

int main() {
    srand((unsigned int)time(nullptr)); // Inisialisasi seed untuk bilangan acak

    cout << "DATA SEBELUM TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() % 100) + 1;
        cout << Data[i] << " ";
    }
    cout << endl;

    SelectionSort(); // Mengurutkan dengan seleksi

    cout << "\nDATA SETELAH TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;

    cout << "Jumlah perbandingan: " << comparisons << endl;
    cout << "Jumlah pergeseran: " << shifts << endl;

    return 0;
}
