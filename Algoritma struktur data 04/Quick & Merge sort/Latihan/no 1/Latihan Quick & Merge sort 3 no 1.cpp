//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10
int Data[MAX];
int temp[MAX]; // Array temporer untuk penggabungan

// Prosedur untuk mencetak data
void cetakData() {
    for (int i = 0; i < MAX; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;
}

// Prosedur penggabungan untuk Merge Sort
void merge(int Data[], int temp[], int kiri, int tengah, int kanan, int& iterasi) {
    int i = kiri;
    int j = tengah;
    int k = kiri;

    while (i < tengah && j <= kanan) {
        if (Data[i] <= Data[j]) {
            temp[k++] = Data[i++];
        }
        else {
            temp[k++] = Data[j++];
        }
    }

    while (i < tengah) {
        temp[k++] = Data[i++];
    }

    while (j <= kanan) {
        temp[k++] = Data[j++];
    }

    // Salin kembali ke array asli
    for (int l = kiri; l <= kanan; l++) {
        Data[l] = temp[l];
    }

    // Menampilkan perubahan setiap iterasi
    cout << "Iterasi " << ++iterasi << ": ";
    cetakData();
}

// Prosedur rekursif untuk Merge Sort
void m_sort(int Data[], int temp[], int kiri, int kanan, int& iterasi) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2; // Membagi array menjadi dua
        m_sort(Data, temp, kiri, tengah, iterasi); // Mengurutkan bagian kiri
        m_sort(Data, temp, tengah + 1, kanan, iterasi); // Mengurutkan bagian kanan
        merge(Data, temp, kiri, tengah + 1, kanan, iterasi); // Menggabungkan dua bagian
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

    int iterasi = 0; // Menghitung jumlah iterasi
    m_sort(Data, temp, 0, MAX - 1, iterasi); // Mengurutkan dengan Merge Sort

    cout << "\nDATA SETELAH TERURUT: ";
    cetakData(); // Menampilkan data setelah diurutkan

    return 0;
}
