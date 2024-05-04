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

// Prosedur pengurutan dengan metode Shell Sort, menampilkan setiap iterasi
void ShellSort() {
    int Jarak = MAX / 2; // Inisialisasi jarak awal
    int iterasi = 1; // Menghitung iterasi
    bool Sudah;

    // Loop untuk mengurangi jarak
    while (Jarak >= 1) {
        Sudah = true; // Asumsikan sudah selesai

        // Loop untuk mengurutkan elemen dengan jarak tertentu
        for (int j = 0; j < MAX - Jarak; j++) {
            int i = j + Jarak;
            if (Data[j] > Data[i]) { // Jika perlu ditukar
                Tukar(&Data[j], &Data[i]);
                Sudah = false; // Belum selesai
            }
        }

        // Cetak data setelah setiap iterasi
        cout << "Iterasi " << iterasi << " (Jarak: " << Jarak << "): ";
        cetakData();

        // Jika sudah selesai, kurangi jarak
        if (Sudah) {
            Jarak /= 2;
        }

        iterasi++; // Tambah iterasi setelah setiap loop jarak
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

    // Mengurutkan dengan Shell Sort dan menampilkan setiap iterasi
    ShellSort();

    return 0;
}
