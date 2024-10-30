#ifndef list_H
#define list_H
#include <stdio.h>
#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
/*deklarasi record dan struktur data list*/
typedef int infotype;
typedef struct elmlist *address;
struct elmlist
{
    infotype info;
    address next;
};
/* definisi list : */
/* list kosong jika First(L)=Nil */
/* setiap elemen address P dapat diacu info(P) atau next(P) */
struct list
{
    address first;
};
/********* pengecekan apakah list kosong ***********/
bool ListEmpty(list L);
/*mengembalikan nilai true jika list kosong*/
/********* pembuatan list kosong *********/
void CreateList(list &L);
/* I.S. sembarang
 F.S. terbentuk list kosong*/

/********* manajemen memori *********/
void dealokasi(address P);
/* I.S. P terdefinisi
 F.S. memori yang digunakan P dikembalikan ke sistem */

/********* pencarian sebuah elemen list *********/
address findElm(list L, infotype X);

bool fFindElm(list L, address P);
/* mencari apakah ada elemen list dengan alamat P
 mengembalikan true jika ada dan false jika tidak ada */
address findBefore(list L, address P);
/* mengembalikan address elemen sebelum P
 jika prec berada pada awal list, maka mengembalikan nilai Nil */

/********* penambahan elemen **********/
void insertFirst(list &L, address P);
/* I.S. sembarang, P sudah dialokasikan
 F.S. menempatkan elemen beralamat P pada awal list */

void insertAfter(list &L, address P, address Prec);
/* I.S. sembarang, P dan Prec alamt salah satu elemen list
 F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */
void insertLast(list &L, address P);
/* I.S. sembarang, P sudah dialokasikan
 F.S. menempatkan elemen beralamat P pada akhir list */

/********* penghapusan sebuah elemen *********/
void delFirst(list &L, address &P);
/* I.S. list tidak kosong
 F.S. adalah alamat dari alamat elemen pertama list
 sebelum elemen pertama list dihapus
 elemen pertama list hilang dan list mungkin menjadi kosong
 first elemen yang baru adalah successor first elemen yang lama */

void delLast(list &L, address &P);
/* I.S. list tidak kosong
 F.S. adalah alamat dari alamat elemen terakhir list
 sebelum elemen terakhir list dihapus
 elemen terakhir list hilang dan list mungkin menjadi kosong
 last elemen yang baru adalah successor last elemen yang lama */

void delAfter(list &L, address &P, address Prec);
/* I.S. list tidak kosng, Prec alamat salah satu elemen list
 F.S. P adalah alamatdari next(Prec), menghapus next(Prec) dari list */

void delP(list &L, infotype X);
/* I.S. sembarang
 F.S. jika ada elemen list dengan alamat P, dimana info(P)=X, maka P
 dihapus
 dan P di-dealokasi, jika tidak ada maka list tetap
 list mungkin akan menjadi kosong karena penghapusan */

/********** proses semau elemen list *********/
void printInfo(list L);
/* I.S. list mungkin kosong
 F.S. jika list tidak kosong menampilkan semua info yang ada pada list */

int nbList(list L);
/* mengembalikan jumlah elemen pada list */
/********** proses terhadap list **********/

void delAll(list &L);
/* menghapus semua elemen list dan semua elemen di-dealokasi */

void invertList(list &L);
/* I.S. sembarang
 F.S. elemen - elemen list dibalik */

void copyList(list L1, list &L2);
/* I.S. L1 sembarang
F.S. L1 = L2, L1 dan L2 menunjuk pada elemen yang sama */
list fCopyList(list L);
/* mengembalikan list yang merupakan salinan dari L */

#endif