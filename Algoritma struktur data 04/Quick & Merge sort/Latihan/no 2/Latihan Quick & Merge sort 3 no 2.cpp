//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10

int Data[MAX];
int temp[MAX]; // Array temporer untuk penggabungan

// Prosedur penggabungan untuk Merge Sort
void merge(int Data[], int temp[], int kiri, int tengah, int kanan, int& perbandingan, int& pergeseran) {
    int i = kiri;
    int j = tengah;
    int k = kiri;

    while (i < tengah && j <= kanan) {
        perbandingan++; // Setiap kali elemen dibandingkan
        if (Data[i] <= Data[j]) {
            temp[k++] = Data[i++];
        }
        else {
            temp[k++] = Data[j++];
            pergeseran++; // Pergeseran saat menyalin
        }
    }

    while (i < tengah) {
        temp[k++] = Data[i++];
        pergeseran++; // Pergeseran saat menyalin
    }

    while (j <= kanan) {
        temp[k++] = Data[j++];
        pergeseran++; // Pergeseran saat menyalin
    }

    for (int l = kiri; l <= kanan; l++) {
        Data[l] = temp[l];
        pergeseran++; // Pergeseran saat menyalin kembali
    }
}

// Prosedur rekursif untuk Merge Sort
void m_sort(int Data[], int temp[], int kiri, int kanan, int& perbandingan, int& pergeseran) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2;
        m_sort(Data, temp, kiri, tengah, perbandingan, pergeseran);
        m_sort(Data, temp, tengah + 1, kanan, perbandingan, pergeseran);
        merge(Data, temp, kiri, tengah + 1, kanan, perbandingan, pergeseran);
    }
}

int main() {
    srand((unsigned int)time(nullptr));

    cout << "DATA SEBELUM TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() % 100) + 1;
        cout << Data[i] << " ";
    }
    cout << endl;

    int perbandingan = 0; // Menghitung jumlah perbandingan
    int pergeseran = 0; // Menghitung jumlah pergeseran

    m_sort(Data, temp, 0, MAX - 1, perbandingan, pergeseran); // Mengurutkan dengan Merge Sort

    cout << "\nDATA SETELAH TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;

    cout << "\nJumlah Perbandingan: " << perbandingan;
    cout << "\nJumlah Pergeseran: " << pergeseran << endl;

    return 0;
}
