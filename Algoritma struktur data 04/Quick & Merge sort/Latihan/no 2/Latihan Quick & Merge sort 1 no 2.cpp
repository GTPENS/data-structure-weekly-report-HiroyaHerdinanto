//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10
#define MaxStack 20 // Ukuran stack untuk partisi non-rekursif

int Data[MAX]; // Array untuk menyimpan data acak

// Prosedur untuk menukar dua elemen dalam array
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur Quick Sort non-rekursif dengan penghitungan perbandingan dan pergeseran
void QuickSortNonRekursif(int& perbandingan, int& pergeseran) {
    struct Stack {
        int kiri;
        int kanan;
    };

    Stack stack[MaxStack]; // Stack untuk menyimpan batas partisi
    int top = 0; // Indeks atas dari stack
    stack[top].kiri = 0; // Batas kiri awal
    stack[top].kanan = MAX - 1; // Batas kanan awal

    while (top >= 0) { // Selama masih ada batas partisi
        int kiri = stack[top].kiri;
        int kanan = stack[top].kanan;
        top--; // Kurangi indeks stack setelah memproses

        int pivot = Data[(kiri + kanan) / 2]; // Pilih pivot di tengah
        int i = kiri;
        int j = kanan;

        while (i <= j) { // Partisi dalam rentang kiri ke kanan
            perbandingan++; // Perbandingan untuk setiap langkah
            while (Data[i] < pivot) {
                i++;
                perbandingan++; // Setiap kali perbandingan
            }
            while (Data[j] > pivot) {
                j--;
                perbandingan++; // Setiap kali perbandingan
            }
            if (i <= j) {
                Tukar(&Data[i], &Data[j]); // Pertukaran elemen
                i++;
                j--;
                pergeseran++; // Pergeseran saat pertukaran
            }
        }

        if (kiri < j) { // Jika ada bagian kiri yang belum diurutkan
            stack[++top].kiri = kiri;
            stack[top].kanan = j;
        }

        if (i < kanan) { // Jika ada bagian kanan yang belum diurutkan
            stack[++top].kiri = i;
            stack[top].kanan = kanan;
        }
    }
}

int main() {
    srand((unsigned int)time(nullptr)); // Menginisialisasi seed untuk bilangan acak

    cout << "DATA SEBELUM TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() % 100) + 1;
        cout << Data[i] << " ";
    }
    cout << endl;

    int perbandingan = 0; // Menghitung jumlah perbandingan
    int pergeseran = 0; // Menghitung jumlah pergeseran

    QuickSortNonRekursif(perbandingan, pergeseran); // Mengurutkan dengan Quick Sort non-rekursif

    cout << "\nDATA SETELAH TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;

    cout << "\nJumlah Perbandingan: " << perbandingan;
    cout << "\nJumlah Pergeseran: " << pergeseran << endl;

    return 0; // Mengembalikan nilai ke sistem operasi
}
