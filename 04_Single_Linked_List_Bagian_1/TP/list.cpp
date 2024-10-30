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