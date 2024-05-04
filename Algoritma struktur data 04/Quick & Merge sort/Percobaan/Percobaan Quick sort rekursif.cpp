//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10
int Data[MAX];

// Prosedur untuk menukar dua elemen
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur Quick Sort dengan pendekatan rekursif
void QuickSortRekursif(int L, int R) {
    int pivot = Data[(L + R) / 2]; // Pilih elemen pivot di tengah
    int i = L; // Indeks awal
    int j = R; // Indeks akhir

    // Partisi elemen berdasarkan pivot
    while (i <= j) {
        while (Data[i] < pivot) {
            i++; // Pindah ke kanan jika lebih kecil dari pivot
        }
        while (Data[j] > pivot) {
            j--; // Pindah ke kiri jika lebih besar dari pivot
        }
        if (i <= j) {
            Tukar(&Data[i], &Data[j]); // Tukar elemen yang melanggar aturan partisi
            i++;
            j--;
        }
    }

    // Rekursi pada bagian kiri dari pivot
    if (L < j) {
        QuickSortRekursif(L, j);
    }

    // Rekursi pada bagian kanan dari pivot
    if (i < R) {
        QuickSortRekursif(i, R);
    }
}

int main() {
    srand((unsigned int)time(nullptr)); // Inisialisasi seed untuk bilangan acak

    cout << "DATA SEBELUM TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() % 100) + 1; // Bilangan acak antara 1 dan 100
        cout << Data[i] << " ";
    }
    cout << endl;

    // Mengurutkan dengan Quick Sort Rekursif
    QuickSortRekursif(0, MAX - 1);

    cout << "\nDATA SETELAH TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;

    return 0; // Mengembalikan nilai ke sistem operasi
}
