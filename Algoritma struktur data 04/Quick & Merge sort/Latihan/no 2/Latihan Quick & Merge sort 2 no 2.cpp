//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10

int Data[MAX];

// Prosedur untuk menukar dua elemen dalam array
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur Quick Sort rekursif dengan penghitungan perbandingan dan pergeseran
void QuickSortRekursif(int kiri, int kanan, int& perbandingan, int& pergeseran) {
    if (kiri < kanan) {
        int pivot = Data[(kiri + kanan) / 2]; // Pivot di tengah
        int i = kiri; // Indeks awal
        int j = kanan; // Indeks akhir

        while (i <= j) { // Partisi elemen
            perbandingan++; // Setiap kali dua elemen dibandingkan
            while (Data[i] < pivot) {
                i++;
                perbandingan++; // Perbandingan pada setiap langkah
            }
            while (Data[j] > pivot) {
                j--;
                perbandingan++; // Perbandingan pada setiap langkah
            }
            if (i <= j) {
                Tukar(&Data[i], &Data[j]); // Pertukaran elemen
                i++;
                j--;
                pergeseran++; // Menghitung setiap kali pertukaran
            }
        }

        // Rekursi pada sub-array kiri
        QuickSortRekursif(kiri, j, perbandingan, pergeseran);

        // Rekursi pada sub-array kanan
        QuickSortRekursif(i, kanan, perbandingan, pergeseran);
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

    int perbandingan = 0; // Menghitung jumlah perbandingan
    int pergeseran = 0; // Menghitung jumlah pergeseran

    QuickSortRekursif(0, MAX - 1, perbandingan, pergeseran); // Mengurutkan dengan Quick Sort rekursif

    cout << "\nDATA SETELAH TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;

    cout << "\nJumlah Perbandingan: " << perbandingan;
    cout << "\nJumlah Pergeseran: " << pergeseran << endl;

    return 0; // Mengembalikan nilai ke sistem operasi
}
