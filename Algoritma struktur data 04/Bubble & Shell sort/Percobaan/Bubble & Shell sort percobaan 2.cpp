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

// Prosedur pengurutan menggunakan metode Shell Sort
void ShellSort() {
    int Jarak, i, j;
    bool Sudah;
    Jarak = MAX; // Awal jarak
    while (Jarak > 1) {
        Jarak = Jarak / 2; // Mengurangi jarak
        Sudah = false; // Penanda apakah sudah selesai
        while (!Sudah) {
            Sudah = true; // Mengasumsikan sudah selesai
            for (j = 0; j < MAX - Jarak; j++) {
                i = j + Jarak; // Elemen dengan jarak tertentu
                if (Data[j] > Data[i]) { // Jika perlu ditukar
                    Tukar(&Data[j], &Data[i]); // Tukar
                    Sudah = false; // Belum selesai
                }
            }
        }
    }
}

int main() {
    srand((unsigned int)time(nullptr)); // Menginisialisasi seed untuk bilangan acak

    cout << "DATA SEBELUM TERURUT:";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() % 100) + 1; // Bilangan acak antara 1 dan 100
        cout << "\nData ke " << i << ": " << Data[i];
    }

    // Mengurutkan menggunakan Shell Sort
    ShellSort();

    cout << "\n\nDATA SETELAH TERURUT:";
    for (int i = 0; i < MAX; i++) {
        cout << "\nData ke " << i << ": " << Data[i];
    }

    cout << endl; 

    return 0; 
}
