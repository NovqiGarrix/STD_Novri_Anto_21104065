// Un-Guided Pilihan Nomor 1 - Data Pegawai dan Proyek

#include <iostream>
#include <string>

using namespace std;

struct Pegawai
{
    string nama;
    string ID;
};

struct Proyek
{
    string nama;
    string durasi;
    Pegawai *pegawai;
    Proyek *next;
};

struct ListProyek
{
    Proyek *first;
};

void createList(ListProyek &L)
{
    L.first = NULL;
}

void insertLast(ListProyek &L, Proyek *P)
{
    if (L.first == NULL)
    {
        L.first = P;
    }
    else
    {
        Proyek *last = L.first;
        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = P;
    }
}

void attachPegawai(Proyek *P, Pegawai *Q)
{
    P->pegawai = Q;
}

Pegawai *createPegawai(string nama, string ID)
{
    Pegawai *P = new Pegawai;
    P->nama = nama;
    P->ID = ID;

    return P;
}

Proyek *createProyek(string nama, string durasi, Pegawai *pegawai)
{
    Proyek *P = new Proyek;
    P->nama = nama;
    P->durasi = durasi;
    P->next = NULL;
    P->pegawai = pegawai;

    return P;
}

void printAll(ListProyek L)
{
    Proyek *P = L.first;
    while (P != NULL)
    {
        cout << "Nama Proyek: " << P->nama << endl;
        cout << "Durasi: " << P->durasi << endl;
        cout << "Nama Pegawai: " << P->pegawai->nama << endl;
        cout << "ID Pegawai: " << P->pegawai->ID << endl;
        cout << endl;

        P = P->next;
    }
}

void deleteProyek(ListProyek &L, string namaProyek)
{
    Proyek *current = L.first;
    Proyek *prev = NULL;

    while (current != NULL)
    {
        if (current->nama == namaProyek)
        {
            if (prev != NULL)
            {
                prev->next = current->next;
            }
            else
            {
                L.first = current->next;
            }

            if (current->pegawai != NULL)
            {
                delete current->pegawai;
            }

            delete current;
            break;
        }

        prev = current;
        current = current->next;
    }
}

int main()
{
    ListProyek listProyek;
    createList(listProyek);

    Pegawai *andi = createPegawai("Andi", "POO1");
    Pegawai *budi = createPegawai("Budi", "POO2");
    Pegawai *citra = createPegawai("Citra", "POO3");

    Proyek *proyekMobile = createProyek("Aplikasi Mobile", "12 bulan", andi);
    Proyek *proyekWeb = createProyek("Sistem Akuntansi", "8 bulan", budi);
    Proyek *proyekECommerce = createProyek("E-Commerce", "10 bulan", citra);
    Proyek *proyekAnalisisData = createProyek("Analisis Data", "6 bulan", andi);

    insertLast(listProyek, proyekMobile);
    insertLast(listProyek, proyekWeb);
    insertLast(listProyek, proyekECommerce);
    insertLast(listProyek, proyekAnalisisData);

    cout << "Sebelum dihapus:" << endl;
    printAll(listProyek);

    deleteProyek(listProyek, "Aplikasi Mobile");

    cout << "Setelah dihapus:" << endl;
    printAll(listProyek);

    return 0;
}