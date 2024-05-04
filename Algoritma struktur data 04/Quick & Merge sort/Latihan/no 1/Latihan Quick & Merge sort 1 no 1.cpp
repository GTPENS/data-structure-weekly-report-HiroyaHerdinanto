//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10
#define MaxStack 10

int Data[MAX]; // Array untuk menyimpan data

// Prosedur untuk menukar dua elemen dalam array
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur untuk mencetak data
void cetakData() {
    for (int i = 0; i < MAX; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;
}

// Prosedur Quick Sort non-rekursif dengan tampilan setiap iterasi
void QuickSortNonRekursif() {
    struct Stack {
        int kiri; // Batas kiri
        int kanan; // Batas kanan
    };

    Stack stack[MaxStack]; // Tumpukan untuk menyimpan batas partisi
    int top = 0; // Indeks atas dari tumpukan
    stack[top].kiri = 0; // Setel batas kiri
    stack[top].kanan = MAX - 1; // Setel batas kanan

    int iterasi = 0; // Menghitung iterasi
    while (top >= 0) { // Selama masih ada batas partisi
        int kiri = stack[top].kiri; // Ambil batas kiri
        int kanan = stack[top].kanan; // Ambil batas kanan
        top--; // Kurangi indeks tumpukan

        // Partisi array
        int i = kiri;
        int j = kanan;
        int pivot = Data[(kiri + kanan) / 2]; // Pivot di tengah

        while (i <= j) {
            while (Data[i] < pivot) { i++; }
            while (Data[j] > pivot) { j--; }
            if (i <= j) {
                Tukar(&Data[i], &Data[j]); // Tukar elemen
                i++;
                j--;
            }
        }

        // Menampilkan perubahan setiap iterasi
        cout << "Iterasi " << ++iterasi << ": ";
        cetakData();

        if (kiri < j) { // Jika ada bagian yang belum diurutkan di sebelah kiri
            stack[++top].kiri = kiri;
            stack[top].kanan = j;
        }

        if (i < kanan) { // Jika ada bagian yang belum diurutkan di sebelah kanan
            stack[++top].kiri = i;
            stack[top].kanan = kanan;
        }
    }
}

int main() {
    srand((unsigned int)time(nullptr)); // Menginisialisasi seed untuk bilangan acak

    cout << "DATA SEBELUM TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() % 100) + 1; // Bilangan acak antara 1 dan 100
        cout << Data[i] << " ";
    }
    cout << endl;

    QuickSortNonRekursif(); // Mengurutkan dengan Quick Sort non-rekursif

    cout << "\nDATA SETELAH TERURUT: ";
    cetakData(); // Menampilkan data setelah diurutkan

    return 0; // Mengembalikan nilai ke sistem operasi
}