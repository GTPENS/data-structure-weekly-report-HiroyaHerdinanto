//Hiroya Herdinanto
//GT11-A
//5223600022

#include <iostream>
#include <cstring>

using namespace std;

struct node {
    char nama[25];
    int nrp;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;
struct node* tail = NULL;

// Alokasi memori
struct node* alokasi_node() {
    struct node* newNode = new node;
    if (newNode == NULL)
        return NULL;
    else {
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }
}
//Menyisipkan simpul pada ujung
void sisipUjung() {
    struct node* newNode = alokasi_node();
    if (newNode == NULL) {
        cout << "Alokasi gagal\n";
        return;
    }

    cout << "Nama : ";
    cin >> newNode->nama;
    cout << "NRP : ";
    cin >> newNode->nrp;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

//Menyisipkan simpul baru sebelum simpul target
void sisipSebelum() {
    if (head == NULL) {
        cout << "Linked list kosong.\n";
        return;
    }

    char namaTarget[25];
    cout << "Masukkan nama simpul yang ingin disisipkan sebelumnya: ";
    cin >> namaTarget;

    // Mencari simpul yang menjadi target sisip
    struct node* current = head;
    while (current != NULL) {
        if (strcmp(current->nama, namaTarget) == 0) {
            break; // Simpul target ditemukan
        }
        current = current->next;
    }

    if (current == NULL) {
        cout << "Simpul dengan nama " << namaTarget << " tidak ditemukan.\n";
        return;
    }

    // Membuat simpul baru
    struct node* newNode = alokasi_node();
    if (newNode == NULL) {
        cout << "Alokasi gagal\n";
        return;
    }

    cout << "Nama : ";
    cin >> newNode->nama;
    cout << "NRP : ";
    cin >> newNode->nrp;

    // Menyisipkan simpul baru sebelum simpul target
    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev != NULL) {
        current->prev->next = newNode;
    }
    else {
        head = newNode; // Jika simpul baru menjadi head
    }
    current->prev = newNode;

    cout << "Simpul berhasil disisipkan sebelum simpul dengan nama " << namaTarget << ".\n";
}

//Menampilkan simpul
void tampilkanList() {
    struct node* current = head;
    while (current != NULL) {
        cout << "Nama: " << current->nama << ", NRP: " << current->nrp << endl;
        current = current->next;
    }
}

//Mencari simpul tertentu
void cariSimpul(const char* nama) {
    struct node* current = head;
    bool found = false;
    while (current != NULL) {
        if (strcmp(current->nama, nama) == 0) {
            found = true;
            cout << "Simpul dengan nama " << nama << " ditemukan. NRP: " << current->nrp << endl;
            break;
        }
        current = current->next;
    }
    if (!found) {
        cout << "Simpul dengan nama " << nama << " tidak ditemukan.\n";
    }
}

//Menghapus simpul depan
void hapusSimpulDepan() {
    if (head == NULL) {
        cout << "Linked list kosong.\n";
        return;
    }

    struct node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}

//Menghapus simpul tertentu/tengah
void hapusSimpulTengah() {
    if (head == NULL) {
        cout << "Linked list kosong.\n";
        return;
    }

    char nama[25];
    cout << "Masukkan nama simpul yang ingin dihapus: ";
    cin >> nama;

    // Mencari simpul yang akan dihapus
    struct node* current = head;
    while (current != NULL) {
        if (strcmp(current->nama, nama) == 0) {
            break; // Simpul ditemukan
        }
        current = current->next;
    }

    if (current == NULL) {
        cout << "Simpul dengan nama " << nama << " tidak ditemukan.\n";
        return;
    }

    // Menghapus simpul
    if (current == head) {
        hapusSimpulDepan(); // Jika simpul yang akan dihapus adalah simpul pertama
    }
    else if (current == tail) {
        hapusSimpulDepan(); // Jika simpul yang akan dihapus adalah simpul terakhir
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        cout << "Simpul dengan nama " << nama << " berhasil dihapus.\n";
    }
}

//Menghapus simpul akhir
void hapusSimpulAkhir() {
    if (head == NULL) {
        cout << "Linked list kosong.\n";
        return;
    }

    struct node* temp = tail;
    tail = tail->prev;
    if (tail != NULL)
        tail->next = NULL;
    delete temp;
}

//Membaca data dengan First In First Out
void bacaFIFO() {
    if (head == NULL) {
        cout << "Linked list kosong.\n";
        return;
    }

    cout << "Membaca simpul menggunakan metode FIFO:\n";
    struct node* current = head;
    while (current != NULL) {
        cout << "Nama: " << current->nama << ", NRP: " << current->nrp << endl;
        current = current->next;
    }
}

//Membaca data dengan Last In First Out
void bacaLIFO() {
    if (tail == NULL) {
        cout << "Linked list kosong.\n";
        return;
    }

    cout << "Membaca simpul menggunakan metode LIFO:\n";
    struct node* current = tail;
    while (current != NULL) {
        cout << "Nama: " << current->nama << ", NRP: " << current->nrp << endl;
        current = current->prev;
    }
}

int main() {
    int pilihan;
    char nama[25];
    int nrp;

    do {
        cout << "\nMenu Operasi Linked List:\n";
        cout << "1. Menyisipkan Simpul Ujung\n";
        cout << "2. Menyisipkan Simpul Sebelum\n";
        cout << "3. Menampilkan Linked List\n";
        cout << "4. Mencari Simpul Tertentu\n";
        cout << "5. Menghapus Simpul Tertentu (Simpul depan)\n";
        cout << "6. Menghapus Simpul Tertentu \n";
        cout << "7. Menghapus Simpul Tertentu (Simpul terakhir)\n";
        cout << "8. Membaca Simpul dengan FIFO\n";
        cout << "9. Membaca Simpul dengan LIFO\n";
        cout << "10. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            sisipUjung();
            break;
        case 2:
            sisipSebelum();
            break;
        case 3:
            tampilkanList();
            break;
        case 4:
            cout << "Masukkan nama yang ingin dicari: ";
            cin >> nama;
            cariSimpul(nama);
            break;
        case 5:
            hapusSimpulDepan();
            break;
        case 6:
            hapusSimpulTengah();
            break;
        case 7:
            hapusSimpulAkhir();
            break;
        case 8:
            bacaFIFO();
            break;
        case 9:
            bacaLIFO();
            break;
        case 10:
            cout << "Terima kasih telah menggunakan program ini.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 9);

    return 0;
}