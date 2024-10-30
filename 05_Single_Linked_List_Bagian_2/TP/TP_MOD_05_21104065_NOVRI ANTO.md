# Laporan Tugas Pendahuluan

## Cover
Nama    : Novri Anto <br>
NIM     : 21104065 <br>
Judul   : Tugas Pendahuluan Modul 05

## Nomor 1
*Soal*: Mencari Elemen Tertentu dalam SLL

*Deskripsi Soal*: Buatlah program yang mengizinkan pengguna memasukkan 6 elemen integer ke dalam list. Implementasikan function `searchElement` untuk mencari apakah sebuah nilai tertentu ada dalam list.

### Intruksi
1. Minta pengguna untuk memasukan nilai yang ingin dicari.
2. Jika nilai ditemukan, tampilan alamat dan posisi dalam angka (contoh: urutan ke 4)
pada list tersebut.
3. Jika nilai tidak ditemukan, tampilkan pesan bahwa elemen tersebut tidak ada dalam
list tersebut.

### NB:
1. Gunakan pendekatan linier search untuk mencari elemen.

### Implementation
```c++
#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node *next;
};

void insertFirst_21104065(Node *&head, int info)
{
    Node *newNode = new Node;
    newNode->info = info;
    newNode->next = head;
    head = newNode;
}

void insertLast_21104065(Node *&head, int info)
{
    Node *newNode = new Node;
    newNode->info = info;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
    }
}

struct List
{
    Node *head;
};

void searchElement_21104065(Node *head, int x)
{
    Node *current = head;
    int position = 1;
    bool found = false;

    while (current != NULL)
    {
        if (current->info == x)
        {
            cout << "Data " << x << " ditemukan pada posisi " << position;
            cout << "\nAddress: " << current << endl;
            found = true;
            break;
        }
        current = current->next;
        position++;
    }

    if (!found)
    {
        cout << "Data " << x << " tidak ditemukan di dalam list" << endl;
    }
}

int main()
{

    List L;
    L.head = NULL;

    int t;

    cout << "Masukkan angka: ";
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int y;
        cout << "Masukkan angka ke-" << i + 1 << ": ";
        cin >> y;
        insertLast_21104065(L.head, y);
    }

    int x;
    cout << "Masukkan angka yang ingin dicari: ";
    cin >> x;

    searchElement_21104065(L.head, x);

    return 0;
}
```

### Output
![Output Nomor 1](<Output_01.png>)

## Nomor 2
*Soal*: Mengurutkan List Menggunakan Bubble Sort

*Deskripsi Soal*: Buatlah program yang mengizinkan pengguna memasukkan 5 elemen integer ke dalam list. Implementasikan procedure bubbleSortList untuk mengurutkan elemen-elemen dalam list dari nilai terkecil ke terbesar.

### Implementation
```c++
#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node *next;
};

void insertFirst_21104065(Node *&head, int info)
{
    Node *newNode = new Node;
    newNode->info = info;
    newNode->next = head;
    head = newNode;
}

void insertLast_21104065(Node *&head, int info)
{
    Node *newNode = new Node;
    newNode->info = info;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
    }
}

struct List
{
    Node *head;
};

void bubbleSort_21104065(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    bool swapped;
    Node *current;
    do
    {
        swapped = false;
        current = head;

        while (current->next != NULL)
        {
            if (current->info > current->next->info)
            {
                int temp = current->info;
                current->info = current->next->info;
                current->next->info = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    List L;
    L.head = NULL;

    int t = 5;

    for (int i = 0; i < t; i++)
    {
        int y;
        cout << "Masukkan angka ke-" << i + 1 << ": ";
        cin >> y;
        insertLast_21104065(L.head, y);
    }

    bubbleSort_21104065(L.head);

    printList(L.head);

    return 0;
}
```

### Output
![Output Nomor 2](<Output_02.png>)

## Nomor 2
*Soal*: Menambahkan Elemen Secara Terurut

*Deskripsi Soal*: Buatlah program yang mengizinkan pengguna memasukkan 4 elemen
integer ke dalam list secara manual. Kemudian, minta pengguna memasukkan elemen
tambahan yang harus ditempatkan di posisi yang sesuai sehingga list tetap terurut.

### Instruksi
1. Implementasikan procedure insertSorted untuk menambahkan elemen baru ke
dalam list yang sudah terurut.
2. Tampilkan list setelah elemen baru dimasukkan.

### Implementation
```c++
#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node *next;
};

struct List
{
    Node *head;
};

void insertSorted_21104065(List &L, int x)
{
    Node *newNode = new Node;
    newNode->info = x;
    newNode->next = NULL;

    if (L.head == NULL)
    {
        L.head = newNode;
    }
    else if (x < L.head->info)
    {
        newNode->next = L.head;
        L.head = newNode;
    }
    else
    {
        Node *temp = L.head;
        while (temp->next != NULL && temp->next->info < x)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    List L;
    L.head = NULL;

    int t = 4;

    for (int i = 0; i < t; i++)
    {
        int y;
        cout << "Masukkan angka ke-" << i + 1 << ": ";
        cin >> y;
        insertSorted_21104065(L, y);
    }

    printList(L.head);

    return 0;
}
```

### Output
![Output Nomor 3](<Output_03.png>)