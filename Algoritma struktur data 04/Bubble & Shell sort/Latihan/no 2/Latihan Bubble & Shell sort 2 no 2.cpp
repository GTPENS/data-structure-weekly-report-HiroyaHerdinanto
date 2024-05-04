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

// Prosedur pengurutan dengan metode Shell Sort, menghitung perbandingan dan pergeseran
void ShellSort(int& perbandingan, int& pergeseran) {
    int Jarak = MAX / 2; // Inisialisasi jarak awal
    int iterasi = 1; // Menghitung iterasi
    while (Jarak >= 1) {
        bool Sudah = true; // Penanda untuk mengetahui apakah urutan sudah benar
        for (int j = 0; j < MAX - Jarak; j++) {
            int i = j + Jarak;
            perbandingan++; // Menghitung perbandingan
            if (Data[j] > Data[i]) { // Jika perlu ditukar
                Tukar(&Data[j], &Data[i]);
                pergeseran++; // Menghitung pergeseran
                Sudah = false; // Urutan belum benar
            }
        }

        cout << "Iterasi " << iterasi << " (Jarak: " << Jarak << "): ";
        cetakData(); // Tampilkan setiap perubahan dalam iterasi

        if (Sudah) { // Jika tidak ada perubahan, kurangi jarak
            Jarak /= 2; // Kurangi jarak
        }

        iterasi++; // Menambah iterasi setiap loop jarak
    }
}

int main() {
    srand((unsigned int)time(nullptr)); // Menginisialisasi seed untuk bilangan acak

    cout << "DATA SEBELUM TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() % 100) + 1; // Bilangan acak
        cout << Data[i] << " ";
    }
    cout << endl;

    int perbandingan = 0;
    int pergeseran = 0;

    // Mengurutkan dengan Shell Sort dan menghitung perbandingan serta pergeseran
    ShellSort(perbandingan, pergeseran);

    cout << "\nDATA SETELAH TERURUT: ";
    cetakData();

    cout << "\nJumlah Perbandingan: " << perbandingan;
    cout << "\nJumlah Pergeseran: " << pergeseran << endl;

    return 0;
}
