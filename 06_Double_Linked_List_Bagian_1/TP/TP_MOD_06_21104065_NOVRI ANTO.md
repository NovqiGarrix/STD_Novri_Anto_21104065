# Laporan Tugas Pendahuluan

## Cover
Nama    : Novri Anto <br>
NIM     : 21104065 <br>
Judul   : Tugas Pendahuluan Modul 06

## Nomor 1
*Soal*: Menambahkan Elemen di Awal dan Akhir DLL

*Deskripsi Soal*: Buatlah program yang mengizinkan pengguna menambahkan elemen ke dalam Double Linked List di awal dan di akhir list.

*Instruksi*:
1. Implementasikan fungsi `insertFirst` untuk menambahkan elemen di awal list.
2. Implementasikan fungsi `insertLast` untuk menambahkan elemen di akhir list.
3. Tampilkan seluruh elemen dalam list dari depan ke belakang setelah penambahan
dilakukan.

*Contoh Input*:
- Input: Masukkan elemen pertama = 10
- Input: Masukkan elemen kedua di awal = 5
- Input: Masukkan elemen ketiga di akhir = 20

*Output*:
- DAFTAR ANGGOTA LIST: 5 <-> 10 <-> 20

### Implementation
```c++
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

struct DLL
{
    Node *head;
    Node *tail;
};

void insertFirst(DLL &list, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = list.head;
    newNode->prev = NULL;

    if (list.head == NULL)
    {
        list.head = newNode;
        list.tail = newNode;
    }
    else
    {
        list.head->prev = newNode;
        list.head = newNode;
    }
}

void insertLast(DLL &list, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list.tail;

    if (list.head == NULL)
    {
        list.head = newNode;
        list.tail = newNode;
    }
    else
    {
        list.tail->next = newNode;
        list.tail = newNode;
    }
}

void printList(DLL list)
{
    cout << "DAFTAR ANGGOTA LIST: ";
    Node *current = list.head;
    while (current != NULL)
    {
        cout << current->data;
        if (current->next != NULL)
        {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << endl;
}

int main()
{

    DLL list;
    list.head = NULL;
    list.tail = NULL;

    insertFirst(list, 10);
    insertFirst(list, 5);
    insertLast(list, 20);

    printList(list);
}
```

### Output
![Output Nomor 1](<Output_01.png>)

## Nomor 2
*Soal*: Menghapus Elemen di Awal dan Akhir DLL

*Deskripsi Soal*: Buatlah program yang memungkinkan pengguna untuk menghapus elemen pertama dan
elemen terakhir dalam Double Linked List.

*Instruksi*:
1. Implementasikan fungsi `deleteFirst` untuk menghapus elemen pertama.
2. Implementasikan fungsi `deleteLast` untuk menghapus elemen terakhir.
3. Tampilkan seluruh elemen dalam list setelah penghapusan dilakukan.

*Contoh Input*:
- Input: Masukkan elemen pertama = 10
- Input: Masukkan elemen kedua di akhir = 15
- Input: Masukkan elemen ketiga di akhir = 20
- Hapus elemen pertama dan terakhir.

*Output*:
- DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: 15

### Implementation
```c++
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

struct DLL
{
    Node *head;
    Node *tail;
};

void insertFirst(DLL &list, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = list.head;
    newNode->prev = NULL;

    if (list.head == NULL)
    {
        list.head = newNode;
        list.tail = newNode;
    }
    else
    {
        list.head->prev = newNode;
        list.head = newNode;
    }
}

void insertLast(DLL &list, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list.tail;

    if (list.head == NULL)
    {
        list.head = newNode;
        list.tail = newNode;
    }
    else
    {
        list.tail->next = newNode;
        list.tail = newNode;
    }
}

void printList(DLL list)
{
    cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: ";
    Node *current = list.head;
    while (current != NULL)
    {
        cout << current->data;
        if (current->next != NULL)
        {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << endl;
}

void deleteFirst(DLL &list)
{
    if (list.head != NULL)
    {
        Node *temp = list.head;
        list.head = list.head->next;
        list.head->prev = NULL;
        delete temp;
    }
}

void deleteLast(DLL &list)
{
    if (list.head != NULL)
    {
        Node *temp = list.tail;
        list.tail = list.tail->prev;
        list.tail->next = NULL;
        delete temp;
    }
}

int main()
{
    DLL list;
    list.head = NULL;
    list.tail = NULL;

    insertFirst(list, 10);
    insertLast(list, 15);
    insertLast(list, 20);

    deleteFirst(list);
    deleteLast(list);

    printList(list);
}
```

### Output
![Output Nomor 2](<Output_02.png>)

## Nomor 3
*Soal*: Menampilkan Elemen dari Depan ke Belakang dan Sebaliknya

*Deskripsi Soal*: Buatlah program yang memungkinkan pengguna memasukkan beberapa elemen ke dalam Doubly Linked List. Setelah elemen dimasukkan, tampilkan seluruh elemen dalam list dari depan ke belakang, kemudian dari belakang ke depan.

*Instruksi*:
1. Implementasikan fungsi untuk menampilkan elemen dari depan ke belakang.
2. Implementasikan fungsi untuk menampilkan elemen dari belakang ke depan.
3. Tambahkan 4 elemen ke dalam list dan tampilkan elemen tersebut dalam dua arah.

*Contoh Input*:
- Input: Masukkan 4 elemen secara berurutan: 1, 2, 3, 4

*Output*:
- Daftar elemen dari depan ke belakang: 1 <-> 2 <-> 3 <-> 4
- Daftar elemen dari belakang ke depan: 4 <-> 3 <-> 2 <-> 1

### Implementation
```c++
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

struct DLL
{
    Node *head;
    Node *tail;
};

void insertFirst(DLL &list, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = list.head;
    newNode->prev = NULL;

    if (list.head == NULL)
    {
        list.head = newNode;
        list.tail = newNode;
    }
    else
    {
        list.head->prev = newNode;
        list.head = newNode;
    }
}

void insertLast(DLL &list, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list.tail;

    if (list.head == NULL)
    {
        list.head = newNode;
        list.tail = newNode;
    }
    else
    {
        list.tail->next = newNode;
        list.tail = newNode;
    }
}

void printList(DLL list)
{
    Node *current = list.head;
    while (current != NULL)
    {
        cout << current->data;
        if (current->next != NULL)
        {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << endl;
}

void printHeadThroughTail(DLL list)
{
    cout << "Daftar elemen dari depan ke belakang: ";
    Node *current = list.head;
    while (current != NULL)
    {
        cout << current->data;
        if (current->next != NULL)
        {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << endl;
}

void printTailThroughHead(DLL list)
{
    cout << "Daftar elemen dari belakang ke depan: ";
    Node *current = list.tail;
    while (current != NULL)
    {
        cout << current->data;
        if (current->prev != NULL)
        {
            cout << " <-> ";
        }
        current = current->prev;
    }
    cout << endl;
}

int main()
{
    DLL list;
    list.head = NULL;
    list.tail = NULL;

    insertFirst(list, 1);
    insertLast(list, 2);
    insertLast(list, 3);
    insertLast(list, 4);

    printHeadThroughTail(list);
    printTailThroughHead(list);
}
```

### Output
![Output Nomor 3](<Output_03.png>)