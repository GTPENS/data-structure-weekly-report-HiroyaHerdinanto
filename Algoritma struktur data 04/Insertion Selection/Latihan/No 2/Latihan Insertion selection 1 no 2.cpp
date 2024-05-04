//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 10
int Data[MAX];

int comparisons = 0; // Menghitung jumlah perbandingan
int shifts = 0; // Menghitung jumlah pergeseran

// Fungsi pengurutan penyisipan langsung
void StraightInsertSort() {
    int i, j, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;

        // Menghitung perbandingan dan pergeseran
        while (j >= 0 && x < Data[j]) {
            comparisons++; // Perbandingan
            Data[j + 1] = Data[j];
            j--;
            shifts++; // Pergeseran
        }
        Data[j + 1] = x;
        shifts++; // Pergeseran saat penyisipan
    }
}

int main() {
    srand((unsigned int)time(nullptr)); // Inisialisasi seed untuk bilangan acak

    cout << "DATA SEBELUM TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() % 100) + 1; // Membangkitkan bilangan acak
        cout << Data[i] << " ";
    }
    cout << endl;

    StraightInsertSort(); // Mengurutkan dengan penyisipan langsung

    cout << "\nDATA SETELAH TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;

    cout << "Jumlah perbandingan: " << comparisons << endl;
    cout << "Jumlah pergeseran: " << shifts << endl;

    return 0;
}
