//Hiroya Herdinanto
//%223600022
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

// Prosedur Quick Sort rekursif dengan tampilan setiap iterasi
void QuickSortRekursif(int kiri, int kanan, int& iterasi) {
    if (kiri < kanan) {
        int pivot = Data[(kiri + kanan) / 2]; // Pivot di tengah
        int i = kiri; // Indeks awal
        int j = kanan; // Indeks akhir

        // Partisi array berdasarkan pivot
        while (i <= j) {
            while (Data[i] < pivot) {
                i++;
            }
            while (Data[j] > pivot) {
                j--;
            }
            if (i <= j) {
                Tukar(&Data[i], &Data[j]);
                i++;
                j--;
            }
        }

        // Menampilkan data setelah partisi
        cout << "Iterasi " << ++iterasi << ": ";
        for (int k = 0; k < MAX; k++) {
            cout << Data[k] << " ";
        }
        cout << endl;

        // Rekursi pada sub-array kiri
        QuickSortRekursif(kiri, j, iterasi);

        // Rekursi pada sub-array kanan
        QuickSortRekursif(i, kanan, iterasi);
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

    int iterasi = 0; // Menghitung jumlah iterasi
    QuickSortRekursif(0, MAX - 1, iterasi); // Mengurutkan dengan Quick Sort rekursif

    cout << "\nDATA SETELAH TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;

    return 0; // Mengembalikan nilai ke sistem operasi
}
