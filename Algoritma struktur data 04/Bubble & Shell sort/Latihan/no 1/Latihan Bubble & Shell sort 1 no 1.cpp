//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10
int Data[MAX];

// Prosedur menukar dua elemen
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

// Prosedur pengurutan metode gelembung dengan tampilan setiap iterasi
void BubbleSort() {
    for (int i = 1; i < MAX; i++) {
        cout << "Iterasi " << i << ": ";
        for (int j = MAX - 1; j >= i; j--) {
            if (Data[j - 1] > Data[j]) { // Jika elemen sebelumnya lebih besar, tukar
                Tukar(&Data[j - 1], &Data[j]);
            }
        }
        cetakData(); // Tampilkan perubahan setelah setiap iterasi
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

    // Mengurutkan dengan Bubble Sort dan menampilkan setiap iterasi
    BubbleSort();

    return 0;
}
