//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10
int Data[MAX];

// Prosedur menukar data
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur pengurutan metode gelembung
void BubbleSort() {
    // Loop untuk setiap iterasi pengurutan
    for (int i = 1; i < MAX - 1; i++) {
        // Melakukan pengurutan dari ujung ke ujung
        for (int j = MAX - 1; j >= i; j--) {
            if (Data[j - 1] > Data[j]) { // Jika data sebelumnya lebih besar, tukar
                Tukar(&Data[j - 1], &Data[j]);
            }
        }
    }
}

int main() {
    srand((unsigned int)time(nullptr)); // Menginisialisasi seed untuk angka acak

    // Membangkitkan bilangan acak untuk data
    cout << "DATA SEBELUM TERURUT";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() % 100) + 1; // Bilangan acak antara 1 dan 100
        cout << "\nData ke " << i << ": " << Data[i];
    }

    // Mengurutkan dengan Bubble Sort
    BubbleSort();

    // Menampilkan data setelah diurutkan
    cout << "\nDATA SETELAH TERURUT";
    for (int i = 0; i < MAX; i++) {
        cout << "\nData ke " << i << ": " << Data[i];
    }

    return 0;
}
