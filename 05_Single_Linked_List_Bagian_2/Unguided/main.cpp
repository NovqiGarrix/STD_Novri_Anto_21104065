#include <iostream>

using namespace std;

struct Mahasiswa
{
    int NIM;
    string nama;
};

struct Node
{
    Mahasiswa info;
    Node *next;
};

struct List
{
    Node *head;
};

void insertLast(List &L, Mahasiswa data)
{
    Node *newNode = new Node;
    newNode->info = data;
    newNode->next = NULL;

    if (L.head == NULL)
    {
        L.head = newNode;
    }
    else
    {
        Node *last = L.head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
    }
}

int findStudentByNIM(List L, int NIM)
{
    Node *current = L.head;
    while (current != NULL)
    {
        if (current->info.NIM == NIM)
        {
            return current->info.NIM;
        }
        current = current->next;
    }
    return -1;
}

int main()
{

    List mahasiswa;
    mahasiswa.head = NULL;

    // Create and insert 5 students
    Mahasiswa mhs1 = {21104065, "Budi Santoso"};
    Mahasiswa mhs2 = {21104066, "Dewi Pratiwi"};
    Mahasiswa mhs3 = {21104067, "Ahmad Hidayat"};
    Mahasiswa mhs4 = {21104068, "Siti Rahayu"};
    Mahasiswa mhs5 = {21104069, "Rini Wulandari"};

    insertLast(mahasiswa, mhs1);
    insertLast(mahasiswa, mhs2);
    insertLast(mahasiswa, mhs3);
    insertLast(mahasiswa, mhs4);
    insertLast(mahasiswa, mhs5);

    // Cari mahasiswa dengan NIM 21104065
    int NIM = 21104065;

    if (findStudentByNIM(mahasiswa, NIM) != -1)
    {
        cout << "Mahasiswa dengan NIM " << NIM << " ditemukan" << endl;
    }
    else
    {
        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan" << endl;
    }
}