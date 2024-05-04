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

// Prosedur untuk mencetak data
void cetakData() {
    for (int i = 0; i < MAX; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;
}

// Prosedur pengurutan dengan metode Bubble Sort, menghitung perbandingan dan pergeseran
void BubbleSort(int& perbandingan, int& pergeseran) {
    for (int i = 1; i < MAX; i++) {
        bool swapped = false; // Penanda untuk mengetahui apakah ada pertukaran
        for (int j = MAX - 1; j >= i; j--) {
            perbandingan++; // Menghitung setiap kali dibandingkan
            if (Data[j - 1] > Data[j]) { // Jika perlu ditukar
                Tukar(&Data[j - 1], &Data[j]);
                pergeseran++; // Menghitung pergeseran
                swapped = true; // Ada pertukaran
            }
        }

        // Tampilkan perubahan pada setiap iterasi
        cout << "Iterasi " << i << ": ";
        cetakData();

        if (!swapped) { // Jika tidak ada pertukaran, urutan sudah benar
            break; // Keluar dari loop
        }
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

    int perbandingan = 0;
    int pergeseran = 0;

    // Mengurutkan dengan Bubble Sort dan menghitung perbandingan serta pergeseran
    BubbleSort(perbandingan, pergeseran);

    cout << "\nDATA SETELAH TERURUT: ";
    cetakData();

    cout << "\nJumlah Perbandingan: " << perbandingan;
    cout << "\nJumlah Pergeseran: " << pergeseran << endl;

    return 0;
}
