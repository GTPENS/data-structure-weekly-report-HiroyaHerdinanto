//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 10
int Data[MAX];

// Fungsi pengurutan penyisipan langsung
void StraightInsertSort() {
    int i, j, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;
        while (j >= 0 && x < Data[j]) {
            Data[j + 1] = Data[j];
            j--;
        }
        Data[j + 1] = x;

        // Menampilkan perubahan pada setiap iterasi
        cout << "Iterasi " << i << ": ";
        for (int k = 0; k < MAX; k++) {
            cout << Data[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand((unsigned int)time(nullptr)); // Inisialisasi seed pengacakan

    cout << "DATA SEBELUM TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() % 100) + 1; // Membangkitkan angka acak
        cout << Data[i] << " ";
    }
    cout << endl;

    StraightInsertSort(); // Pengurutan dengan penyisipan langsung

    return 0; // Mengembalikan nilai ke sistem operasi
}

