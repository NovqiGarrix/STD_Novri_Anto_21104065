# Laporan Tugas Pendahuluan

## Cover
Nama    : Novri Anto <br>
NIM     : 21104065 <br>
Judul   : Tugas Pendahuluan Modul 04

## List.h
```c++
#include <iostream>

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;

typedef int infotype;

typedef struct elmlist *address;

struct elmlist
{
    infotype info;
    address next;
};

struct List
{
    address first;
};

void createList(List *L);

address allocate(infotype x);

void insertFirst(List &L, address P);

void printInfo(List L);

void insertLast(List &L, address P);

void insertAfter(address Prec, address P);

void deleteLast(List &L, address &P);

void deleteAfter(address Prec, address &P);

address searchInfo(List L, infotype x);
```

### Penjelasan Kode

#### createList
```c++
void createList(List *L);
```
Membuat list baru dengan menginisialisasi pointer `first` pada list menjadi `NULL`.

#### allocate
```c++
address allocate(infotype x);
```
Mengalokasikan memori untuk elemen baru dan mengisi informasi elemen dengan nilai `x`.

#### insertFirst
```c++
void insertFirst(List &L, address P);
```
Menambahkan elemen baru di awal list.

#### printInfo
```c++
void printInfo(List L);
```
Mencetak semua informasi elemen dalam list.

#### insertLast
```c++
void insertLast(List &L, address P);
```
Menambahkan elemen baru di akhir list.

#### insertAfter
```c++
void insertAfter(address Prec, address P);
```
Menambahkan elemen baru setelah elemen tertentu dalam list.

#### deleteLast
```c++
void deleteLast(List &L, address &P);
```
Menghapus elemen terakhir dari list.

#### deleteAfter
```c++
void deleteAfter(address Prec, address &P);
```
Menghapus elemen setelah elemen tertentu dalam list.

#### searchInfo
```c++
address searchInfo(List L, infotype x);
```
Mencari elemen dalam list berdasarkan nilai informasi.

## List.cpp
```c++
#include <iostream>
#include "list.h"

using namespace std;

void createList(List *L)
{
    L->first = NULL;
}

address allocate(infotype x)
{
    address p = new elmlist;
    p->info = x;
    p->next = NULL;

    return p;
}

void insertFirst(List &L, address P)
{
    P->next = L.first;
    L.first = P;
}

void printInfo(List L)
{
    address p = L.first;

    cout << "Isi list: ";

    while (p != NULL)
    {
        cout << p->info;
        p = p->next;
    }
}

void insertLast(List &L, address P)
{
    address p = L.first;

    if (p == NULL)
    {
        L.first = P;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = P;
    }
}

void insertAfter(address Prec, address P)
{
    P->next = Prec->next;
    Prec->next = P;
}

void deleteLast(List &L, address &P)
{
    address p = L.first;

    if (p == P)
    {
        L.first = NULL;
    }
    else
    {
        while (p->next != P)
        {
            p = p->next;
        }

        p->next = NULL;
    }
}

void deleteAfter(address Prec, address &P)
{
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}

address searchInfo(List L, infotype x)
{

    address p = L.first;

    while (p != NULL)
    {
        if (p->info == x)
        {
            return p;
        }

        p = p->next;
    }

    return NULL;
}
```

### Penjelasan Kode
#### createList
```c++
void createList(List *L)
```
Fungsi ini menginisialisasi list baru dengan mengatur pointer `first` pada list menjadi `NULL`, menandakan bahwa list tersebut kosong.

#### allocate
```c++
address allocate(infotype x)
```
Fungsi ini mengalokasikan memori untuk elemen baru, mengisi elemen tersebut dengan nilai `x`, dan mengatur pointer `next` elemen tersebut menjadi `NULL`.

#### insertFirst
```c++
void insertFirst(List &L, address P)
```
Fungsi ini menambahkan elemen baru di awal list dengan mengatur pointer `next` dari elemen baru (`P`) ke elemen pertama saat ini, kemudian mengatur elemen pertama list (`first`) menjadi elemen baru tersebut.

#### printInfo
```c++
void printInfo(List L)
```
Fungsi ini mencetak semua informasi elemen dalam list dengan mengiterasi dari elemen pertama hingga elemen terakhir.

#### insertLast
```c++
void insertLast(List &L, address P)
```
Fungsi ini menambahkan elemen baru di akhir list. Jika list kosong, elemen baru menjadi elemen pertama. Jika tidak, fungsi ini mengiterasi hingga elemen terakhir dan menambahkan elemen baru di akhir.

#### insertAfter
```c++
void insertAfter(address Prec, address P)
```
Fungsi ini menambahkan elemen baru setelah elemen tertentu (`Prec`) dengan mengatur pointer `next` dari elemen baru (`P`) ke elemen setelah `Prec`, dan mengatur pointer `next` dari `Prec` ke elemen baru (`P`).

#### deleteLast
```c++
void deleteLast(List &L, address &P)
```
Fungsi ini menghapus elemen terakhir dari list. Jika elemen terakhir adalah elemen pertama, list menjadi kosong. Jika tidak, fungsi ini mengiterasi hingga elemen sebelum terakhir dan mengatur pointer `next` elemen tersebut menjadi `NULL`.

#### deleteAfter
```c++
void deleteAfter(address Prec, address &P)
```
Fungsi ini menghapus elemen setelah elemen tertentu (`Prec`) dengan mengatur pointer `next` dari `Prec` ke elemen setelah elemen yang dihapus (`P`), dan mengatur pointer `next` dari elemen yang dihapus (`P`) menjadi `NULL`.

#### searchInfo
```c++
address searchInfo(List L, infotype x)
```
Fungsi ini mencari elemen dalam list berdasarkan nilai informasi (`x`). Fungsi ini mengiterasi dari elemen pertama hingga elemen terakhir dan mengembalikan alamat elemen yang ditemukan atau `NULL` jika tidak ditemukan.

## Main.cpp (1)
```c++
#include <iostream>
#include "list.cpp"

using namespace std;

int main()
{

    List L;

    // 1. Panggil create list
    createList(&L);

    // 2. Minta user input
    int n;

    cout << "Masukkan data ke-1: ";
    cin >> n;

    // 3. Panggil fungsi allocate
    address nElm = allocate(n);

    // 4. Panggil insert first
    insertFirst(L, nElm);

    // 5. Panggil show info
    printInfo(L);

    // 2. Minta user input
    int o;

    cout << "Masukkan data ke-2: ";
    cin >> o;

    // 3. Panggil fungsi allocate
    address oElm = allocate(o);

    // 4. Panggil insert first
    insertFirst(L, oElm);

    // 5. Panggil show info
    printInfo(L);

    // 2. Minta user input
    int p;

    cout << "Masukkan data ke-3: ";
    cin >> p;

    // 3. Panggil fungsi allocate
    address pElm = allocate(p);

    // 4. Panggil insert first
    insertFirst(L, pElm);

    // 5. Panggil show info
    printInfo(L);

    return 0;
}
```
### Penjelasan Kode

#### Main.cpp
```c++
int main()
```
Fungsi `main` adalah titik awal program pertama kali dijalankan. Berikut adalah tahapan yang terjadi dalam fungsi `main`:

1. Membuat list baru `L` dengan memanggil `createList(&L)`.
2. Meminta input dari pengguna untuk data pertama, kedua, dan ketiga.
3. Mengalokasikan memori untuk elemen baru dengan memanggil `allocate` untuk setiap input.
4. Menambahkan elemen baru di awal list dengan memanggil `insertFirst`.
5. Mencetak informasi elemen dalam list setelah setiap penambahan elemen dengan memanggil `printInfo`.

Program ini secara bertahap membangun list dengan tiga elemen yang dimasukkan oleh pengguna dan mencetak isi list setelah setiap penambahan elemen.

## Main.cpp (2)
```c++
#include <iostream>
#include "list.cpp"

using namespace std;

int main()
{

    List L;

    // 1. Panggil create list
    createList(&L);

    int total_digit_nim = 10;

    for (int i = 0; i < total_digit_nim; i++)
    {
        int n;

        cout << "Masukkan data ke-" << i + 1 << ": ";
        cin >> n;

        address nElm = allocate(n);

        insertLast(L, nElm);
    }

    printInfo(L);

    return 0;
}
```

### Penjelasan Kode
#### Main.cpp
```c++
int main()
```
Fungsi `main` adalah titik awal program pertama kali dijalankan. Berikut adalah tahapan yang terjadi dalam fungsi `main`:

1. Membuat list baru `L` dengan memanggil `createList(&L)`.
2. Menentukan jumlah total digit NIM yang akan dimasukkan ke dalam list.
3. Menggunakan loop untuk meminta input dari pengguna sebanyak `total_digit_nim` kali.
4. Mengalokasikan memori untuk elemen baru dengan memanggil `allocate` untuk setiap input.
5. Menambahkan elemen baru di akhir list dengan memanggil `insertLast`.
6. Mencetak informasi elemen dalam list setelah semua elemen dimasukkan dengan memanggil `printInfo`.

Program ini secara bertahap membangun list dengan sepuluh elemen yang dimasukkan oleh pengguna dan mencetak isi list setelah semua elemen ditambahkan.
