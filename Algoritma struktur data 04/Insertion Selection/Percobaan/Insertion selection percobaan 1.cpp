//Hiroya Herdinanto
//5223600022
//GT11-A

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; // Menggunakan namespace std

#define MAX 10
int Data[MAX];

// Fungsi pengurutan penyisipan langsung
void StraightInsertSort() {
    int i, j, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;
        while (j >= 0 && x < Data[j]) { // Pastikan j tidak kurang dari 0
            Data[j + 1] = Data[j];
            j--;
        }
        Data[j + 1] = x;
    }
}

int main() {
    srand((unsigned int)time(nullptr)); // Inisialisasi seed untuk pengacakan

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() / 1000) + 1; // Membuat angka acak
        cout << "\nData ke " << i << ": " << Data[i];
    }

    // Memanggil fungsi pengurutan
    StraightInsertSort();

    // Data setelah terurut
    cout << "\nDATA SETELAH TERURUT";
    for (int i = 0; i < MAX; i++) {
        cout << "\nData ke " << i << ": " << Data[i];
    }

    return 0; // Mengembalikan nilai ke sistem operasi
}
