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

// Fungsi untuk mencetak daftar Pegawai
void cetakPegawai(const Pegawai pegawai[], int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        cout << "NIP: " << pegawai[i].NIP << ", Nama: " << pegawai[i].Nama << endl;
    }
    cout << "--------------------------" << endl; // Separator
}

// Fungsi untuk mengurutkan berdasarkan NIP secara urut naik
bool urutNIPNaik(const Pegawai& a, const Pegawai& b) {
    return a.NIP < b.NIP;
}

// Fungsi untuk mengurutkan berdasarkan NIP secara urut turun
bool urutNIPTurun(const Pegawai& a, const Pegawai& b) {
    return a.NIP > b.NIP;
}

// Fungsi untuk mengurutkan berdasarkan Nama secara urut naik
bool urutNamaNaik(const Pegawai& a, const Pegawai& b) {
    return a.Nama < b.Nama;
}

// Fungsi untuk mengurutkan berdasarkan Nama secara urut turun
bool urutNamaTurun(const Pegawai& a, const Pegawai& b) {
    return a.Nama > b.Nama;
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
    char pilihanMetode = '\0', pilihanKriteria = '\0';
    cout << "Pilih Metode Pengurutan:\n";
    cout << "a. Urut naik\nb. Urut turun\n";
    cout << "Masukkan pilihan: ";
    cin >> pilihanMetode;

    cout << "Pilih Kriteria Pengurutan:\n";
    cout << "a. NIP\nb. Nama\n";
    cout << "Masukkan pilihan: ";
    cin >> pilihanKriteria;

    // Pengurutan berdasarkan pilihan
    if (pilihanKriteria == 'a') { // Pengurutan berdasarkan NIP
        if (pilihanMetode == 'a') { // Urut naik
            sort(pegawai, pegawai + jumlahPegawai, urutNIPNaik);
        }
        else if (pilihanMetode == 'b') { // Urut turun
            sort(pegawai, pegawai + jumlahPegawai, urutNIPTurun);
        }
    }
    else if (pilihanKriteria == 'b') { // Pengurutan berdasarkan Nama
        if (pilihanMetode == 'a') { // Urut naik
            sort(pegawai, pegawai + jumlahPegawai, urutNamaNaik);
        }
        else jika(pilihanMetode == 'b') { // Urut turun
            sort(pegawai, pegawai + jumlahPegawai, urutNamaTurun);
        }
    }
    else {
        cout << "Pilihan kriteria tidak valid." << endl; // Kesalahan input
        return 1; // Menghentikan program dengan kesalahan
    }

    cout << "\nDaftar Pegawai Setelah Terurut:\n";
    cetakPegawai(pegawai, jumlahPegawai);

    return 0;
}
