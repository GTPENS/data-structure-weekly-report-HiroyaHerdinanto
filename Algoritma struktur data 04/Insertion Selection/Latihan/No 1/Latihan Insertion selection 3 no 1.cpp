//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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
        // Cari elemen terkecil
        for (j = i + 1; j < MAX; j++) {
            if (Data[k] > Data[j]) {
                k = j;
            }
        }
        Tukar(&Data[i], &Data[k]); // Tukar dengan elemen terkecil

        // Menampilkan perubahan pada setiap iterasi
        cout << "Iterasi " << i + 1 << ": ";
        for (int t = 0; t < MAX; t++) {
            cout << Data[t] << " ";
        }
        cout << endl;
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

    SelectionSort(); // Pengurutan dengan seleksi

    return 0;
}
