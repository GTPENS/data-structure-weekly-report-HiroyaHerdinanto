//Hiroya Herdinanto
//5223600022
//GT11-A
#include <iostream>
#include <algorithm> 
#include <string>

using namespace std;

// Struktur data untuk Pegawai
struct Pegawai {
    int NIP; // Nomor Induk Pegawai
    string Nama; // Nama pegawai
};

// Prosedur menukar dua elemen
void Tukar(Pegawai* a, Pegawai* b) {
    Pegawai temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur pengurutan Bubble Sort
void BubbleSort(Pegawai pegawai[], int ukuran, bool urutNaik) {
    for (int i = 0; i < ukuran - 1; i++) {
        for (int j = ukuran - 1; j > i; j--) {
            if (urutNaik ? (pegawai[j - 1].NIP > pegawai[j].NIP) : (pegawai[j - 1].NIP < pegawai[j].NIP)) {
                Tukar(&pegawai[j - 1], &pegawai[j]);
            }
        }
    }
}

// Prosedur pengurutan Shell Sort
void ShellSort(Pegawai pegawai[], int ukuran, bool urutNaik) {
    int jarak = ukuran / 2;
    while (jarak > 0) {
        for (int i = jarak; i < ukuran; i++) {
            Pegawai temp = pegawai[i];
            int j;
            for (j = i; j >= jarak && (urutNaik ? (pegawai[j - jarak].NIP > temp.NIP) : (pegawai[j - jarak].NIP < temp.NIP)); j -= jarak) {
                pegawai[j] = pegawai[j - jarak];
            }
            pegawai[j] = temp;
        }
        jarak /= 2;
    }
}

// Fungsi untuk mencetak daftar Pegawai
void cetakPegawai(const Pegawai pegawai[], int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        cout << "NIP: " << pegawai[i].NIP << ", Nama: " << pegawai[i].Nama << endl;
    }
}

// Fungsi untuk mengurutkan berdasarkan kriteria dan metode yang dipilih
void urutkanPegawai(Pegawai pegawai[], int ukuran, char metode, char arah, char kriteria) {
    bool urutNaik = (arah == 'a'); // Urut naik jika arah adalah 'a'
    if (kriteria == 'a') { // Pengurutan berdasarkan NIP
        if (metode == 'a') { // Bubble Sort
            BubbleSort(pegawai, ukuran, urutNaik);
        }
        else if (metode == 'b') { // Shell Sort
            ShellSort(pegawai, ukuran, urutNaik);
        }
    }
    else if (kriteria == 'b') { // Pengurutan berdasarkan Nama
        auto cmp = urutNaik ? [](const Pegawai& a, const Pegawai& b) { return a.Nama < b.Nama; }
        : [](const Pegawai& a, const Pegawai& b) { return a.Nama > b.Nama; };
        std::sort(pegawai, pegawai + ukuran, cmp); // Urut berdasarkan Nama
    }
}

int main() {
    const int jumlahPegawai = 6; // Jumlah pegawai dalam array
    Pegawai pegawai[jumlahPegawai] = {
        {21, "Ardy"},
        {22, "Hiro"},
        {53, "Sufa"},
        {23, "Yoga"},
        {24, "Dio"},
        {25, "Bintang"}
    };

    cout << "Daftar Pegawai Sebelum Terurut:\n";
    cetakPegawai(pegawai, jumlahPegawai);

    // Pilih metode pengurutan dan kriteria
    char metode, arah, kriteria;
    cout << "\nPilih Metode Pengurutan:\n";
    cout << "a. Bubble Sort\nb. Shell Sort\n";
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
    urutkanPegawai(pegawai, jumlahPegawai, metode, arah, kriteria);

    cout << "\nDaftar Pegawai Setelah Terurut:\n";
    cetakPegawai(pegawai, jumlahPegawai);

    return 0;
}
