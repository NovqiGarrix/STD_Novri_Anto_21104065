#include <iostream>
#include "singlelist.cpp"
#include "singlelist.h"

using namespace std;

int sumInfo(List L)
{
    address P = L.First;
    int sum = 0;
    while (P != NULL)
    {
        sum += P->info;
        P = P->next;
    }
    return sum;
}

int main()
{
    List L;
    address P1, P2, P3, P4, P5 = NULL;
    CreateList(L);
    P1 = alokasi(2);
    insertFirst(L, P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L, P3);
    P4 = alokasi(12);
    insertFirst(L, P4);
    P5 = alokasi(9);
    insertFirst(L, P5);
    printInfo(L);

    if (findElm(L, 8))
    {
        cout << "8 ditemukan dalam list" << endl;
    }
    else
    {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    cout << "Total info semua elemen adalah " << sumInfo(L) << endl;

    return 0;
}