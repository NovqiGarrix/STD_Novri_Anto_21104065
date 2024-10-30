#include <iostream>
#include "singlelist.h"

using namespace std;

void CreateList(List &L)
{
    L.First = NULL;
}

address alokasi(infotype x)
{
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P)
{
    delete P;
}

void printInfo(List L)
{
    address P = L.First;
    while (P != NULL)
    {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P)
{
    P->next = L.First;
    L.First = P;
}

address findElm(List L, infotype x)
{
    address P = L.First;
    while (P != NULL && P->info != x)
    {
        P = P->next;
    }
    return P;
}