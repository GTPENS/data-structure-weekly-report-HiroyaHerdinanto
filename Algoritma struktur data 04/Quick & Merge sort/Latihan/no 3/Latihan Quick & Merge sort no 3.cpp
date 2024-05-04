//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur data untuk Pegawai
struct Pegawai {
    int NIP; // Nomor Induk Pegawai
    string Nama; // Nama pegawai
};

// Prosedur untuk menukar dua elemen dalam array
void Tukar(Pegawai* a, Pegawai* b) {
    Pegawai temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur pengurutan dengan Merge Sort
void merge(vector<Pegawai>& pegawai, vector<Pegawai>& temp, int kiri, int tengah, int kanan, bool urutNaik, bool urutNIP) {
    int i = kiri;
    int j = tengah;
    int k = kiri;

    while (i < tengah && j <= kanan) {
        if (urutNIP) {
            if (urutNaik ? pegawai[i].NIP <= pegawai[j].NIP : pegawai[i].NIP >= pegawai[j].NIP) {
                temp[k++] = pegawai[i++];
            }
            else {
                temp[k++] = pegawai[j++];
            }
        }
        else {
            if (urutNaik ? pegawai[i].Nama <= pegawai[j].Nama : pegawai[i].Nama >= pegawai[j].Nama) {
                temp[k++] = pegawai[i++];
            }
            else {
                temp[k++] = pegawai[j++];
            }
        }
    }

    while (i < tengah) {
        temp[k++] = pegawai[i++];
    }

    while (j <= kanan) {
        temp[k++] = pegawai[j++];
    }

    for (int m = kiri; m <= kanan; m++) {
        pegawai[m] = temp[m];
    }
}

// Prosedur rekursif untuk Merge Sort
void mergeSort(vector<Pegawai>& pegawai, vector<Pegawai>& temp, int kiri, int kanan, bool urutNaik, bool urutNIP) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2; // Membagi array menjadi dua bagian
        mergeSort(pegawai, temp, kiri, tengah, urutNaik, urutNIP); // Mengurutkan bagian kiri
        mergeSort(pegawai, temp, tengah + 1, kanan, urutNaik, urutNIP); // Mengurutkan bagian kanan
        merge(pegawai, temp, kiri, tengah + 1, kanan, urutNaik, urutNIP); // Menggabungkan dua bagian
    }
}

// Prosedur pengurutan Quick Sort
void QuickSort(vector<Pegawai>& pegawai, int kiri, int kanan, bool urutNaik, bool urutNIP) {
    if (kiri < kanan) {
        int pivotIndex = (kiri + kanan) / 2;
        Pegawai pivot = pegawai[pivotIndex];
        int i = kiri;
        int j = kanan;

        while (i <= j) {
            if (urutNIP) {
                while (urutNaik ? pegawai[i].NIP < pivot.NIP : pegawai[i].NIP > pivot.NIP) {
                    i++;
                }
                while (urutNaik ? pegawai[j].NIP > pivot.NIP : pegawai[j].NIP < pivot.NIP) {
                    j--;
                }
            }
            else {
                while (urutNaik ? pegawai[i].Nama < pivot.Nama : pegawai[i].Nama > pivot.Nama) {
                    i++;
                }
                while (urutNaik ? pegawai[j].Nama > pivot.Nama : pegawai[j].Nama < pivot.Nama) {
                    j--;
                }
            }
            if (i <= j) {
                Tukar(&pegawai[i], &pegawai[j]);
                i++;
                j--;
            }
        }

        QuickSort(pegawai, kiri, j, urutNaik, urutNIP);
        QuickSort(pegawai, i, kanan, urutNaik, urutNIP);
    }
}

// Prosedur untuk mencetak daftar Pegawai
void cetakPegawai(const vector<Pegawai>& pegawai) {
    for (const auto& p : pegawai) {
        cout << "NIP: " << p.NIP << ", Nama: " << p.Nama << endl;
    }
}

// Prosedur untuk mengurutkan berdasarkan metode dan kriteria yang dipilih
void urutkanPegawai(vector<Pegawai>& pegawai, char metode, char arah, char kriteria) {
    bool urutNaik = (arah == 'a'); // Urut naik jika arah 'a'
    bool urutNIP = (kriteria == 'a'); // Urut berdasarkan NIP jika kriteria 'a'

    if (metode == 'a') { // Quick Sort
        QuickSort(pegawai, 0, pegawai.size() - 1, urutNaik, urutNIP);
    }
    else if (metode == 'b') { // Merge Sort
        vector<Pegawai> temp(pegawai.size()); // Array temporer untuk Merge Sort
        mergeSort(pegawai, temp, 0, pegawai.size() - 1, urutNaik, urutNIP);
    }
    else {
        cout << "Metode pengurutan tidak valid." << endl;
    }
}

int main() {
    vector<Pegawai> pegawai = {
        {21, "Ardy"},
        {22, "Hiro"},
        {53, "Sufa"},
        {23, "Yoga"},
        {24, "Dio"},
        {25, "Bintang"}
    };

    cout << "Daftar Pegawai Sebelum Terurut:\n";
    cetakPegawai(pegawai);

    // Pilih metode pengurutan dan kriteria
    char metode, arah, kriteria;
    cout << "\nPilih Metode Pengurutan:\n";
    cout << "a. Quick Sort\nb. Merge Sort\n"; // Posisi Quick Sort dan Merge Sort ditukar
    cout << "Masukkan pilihan: ";
    cin >> metode;

    cout << "\nPilih Arah Pengurutan:\n";
    cout << "a. Urut naik\nb. Urut turun\n";
    cout << "Masukkan pilihan: ";
    cin >> arah;

    cout << "\nPilih Kriteria Pengurutan:\n";
    cout << "a. NIP\nb. Nama\n";
    cout << "Masukkan pilihan: ";
    cin >> kriteria;

    // Urutkan berdasarkan pilihan pengguna
    urutkanPegawai(pegawai, metode, arah, kriteria); // Mengurutkan dengan metode yang dipilih

    cout << "\nDaftar Pegawai Setelah Terurut:\n";
    cetakPegawai(pegawai); // Menampilkan daftar pegawai yang sudah diurutkan

    return 0; // Mengembalikan nilai ke sistem operasi
}
