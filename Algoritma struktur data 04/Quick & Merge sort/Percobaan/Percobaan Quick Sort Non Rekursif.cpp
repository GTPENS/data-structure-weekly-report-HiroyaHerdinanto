//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10
#define MaxStack 10

int Data[MAX]; // Array untuk menyimpan data acak

// Prosedur untuk menukar dua elemen
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

// Prosedur pengurutan menggunakan metode Quick Sort non-rekursif
void QuickSortNonRekursif() {
    struct Tumpukan {
        int Kiri; // Batas kiri
        int Kanan; // Batas kanan
    } stack[MaxStack];

    int ujung = 0; // Indeks tumpukan
    stack[ujung].Kiri = 0;
    stack[ujung].Kanan = MAX - 1;

    while (ujung >= 0) {
        int L = stack[ujung].Kiri;
        int R = stack[ujung].Kanan;
        ujung--; // Kurangi indeks tumpukan saat memproses

        while (L < R) { // Pengurutan dalam rentang L ke R
            int pivot = Data[(L + R) / 2]; // Pivot di tengah
            int i = L;
            int j = R;

            while (i <= j) {
                while (Data[i] < pivot) {
                    i++; // Pindah ke kanan jika elemen lebih kecil dari pivot
                }
                while (Data[j] > pivot) {
                    j--; // Pindah ke kiri jika elemen lebih besar dari pivot
                }
                if (i <= j) {
                    Tukar(&Data[i], &Data[j]); // Tukar elemen yang melanggar urutan
                    i++;
                    j--;
                }
            }

            if (L < j) { // Jika masih ada bagian yang belum diurutkan di sebelah kiri
                ujung++;
                stack[ujung].Kiri = L;
                stack[ujung].Kanan = j;
            }

            L = i; // Teruskan ke bagian kanan yang belum diurutkan
        }
    }
}

int main() {
    srand((unsigned int)time(nullptr)); // Menginisialisasi seed untuk bilangan acak

    cout << "DATA SEBELUM TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() % 100) + 1; // Membangkitkan bilangan acak
        cout << Data[i] << " ";
    }
    cout << endl;

    QuickSortNonRekursif(); // Mengurutkan dengan Quick Sort non-rekursif

    cout << "\nDATA SETELAH TERURUT: ";
    cetakData(); // Menampilkan data setelah diurutkan

    return 0; // Mengembalikan nilai ke sistem operasi
}
