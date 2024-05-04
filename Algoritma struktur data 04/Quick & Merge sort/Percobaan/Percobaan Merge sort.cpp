//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10
int Data[MAX]; // Array untuk menyimpan data
int temp[MAX]; // Array temporer untuk penggabungan (merge)

// Prosedur untuk menggabungkan dua sub-array
void merge(int Data[], int temp[], int kiri, int tengah, int kanan) {
    int i = kiri; // Awal sub-array kiri
    int j = tengah; // Awal sub-array kanan
    int k = kiri; // Posisi dalam array temporer

    // Menggabungkan dua sub-array
    while (i < tengah && j <= kanan) {
        if (Data[i] <= Data[j]) { // Elemen di kiri lebih kecil atau sama dengan kanan
            temp[k++] = Data[i++];
        }
        else { // Elemen di kanan lebih kecil
            temp[k++] = Data[j++];
        }
    }

    // Menyalin sisa elemen dari kiri, jika ada
    while (i < tengah) {
        temp[k++] = Data[i++];
    }

    // Menyalin sisa elemen dari kanan, jika ada
    while (j <= kanan) {
        temp[k++] = Data[j++];
    }

    // Menyalin kembali dari array temporer ke array Data
    for (i = kiri; i <= kanan; i++) {
        Data[i] = temp[i];
    }
}

// Prosedur Merge Sort rekursif
void m_sort(int Data[], int temp[], int kiri, int kanan) {
    if (kiri < kanan) { // Jika lebih dari satu elemen
        int tengah = (kiri + kanan) / 2;
        m_sort(Data, temp, kiri, tengah); // Mengurutkan sub-array kiri
        m_sort(Data, temp, tengah + 1, kanan); // Mengurutkan sub-array kanan
        merge(Data, temp, kiri, tengah + 1, kanan); // Menggabungkan dua sub-array
    }
}

// Prosedur utama untuk mengurutkan dengan Merge Sort
void mergeSort(int Data[], int temp[], int ukuran) {
    m_sort(Data, temp, 0, ukuran - 1); // Memulai pengurutan
}

int main() {
    srand((unsigned int)time(nullptr)); // Inisialisasi seed untuk bilangan acak

    cout << "DATA SEBELUM TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = (rand() % 100) + 1; // Membangkitkan bilangan acak
        cout << Data[i] << " ";
    }
    cout << endl;

    mergeSort(Data, temp, MAX); // Mengurutkan dengan Merge Sort

    cout << "\nDATA SETELAH TERURUT: ";
    for (int i = 0; i < MAX; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;

    return 0; // Mengembalikan nilai ke sistem operasi
}
