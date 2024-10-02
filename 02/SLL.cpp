#include <iostream>
#include "SLL.h"

using namespace std;

void Create_List(List *L)
{
    L->first = NULL;
}

adr New_Element(infotype data)
{
    adr p = new ElmtList;
    p->info = data;
    p->next = NULL;
    return p;
}

void Insert_First(List *L, adr *p)
{
    (*p)->next = L->first;
    L->first = *p;
}

void Insert_Last(List *L, adr *p)
{
    adr last = L->first;
    if (last == NULL)
    {
        L->first = *p;
    }
    else
    {
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = *p;
    }
}

void Insert_After(List *L, adr *p, adr *prec)
{
    (*p)->next = (*prec)->next;
    (*prec)->next = *p;
}

void Delete_First(List *L, adr *p)
{
    *p = L->first;
    L->first = L->first->next;
    (*p)->next = NULL;
}

void Delete_Last(List *L, adr *p)
{
    adr last = L->first;
    if (last->next == NULL)
    {
        *p = last;
        L->first = NULL;
    }
    else
    {
        while (last->next->next != NULL)
        {
            last = last->next;
        }
        *p = last->next;
        last->next = NULL;
    }
}

void Delete_After(List *L, adr *prec, adr *p)
{
    *p = (*prec)->next;
    (*prec)->next = (*p)->next;
    (*p)->next = NULL;
}

void Show(List *L)
{
    if (L->first == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        adr p = L->first;
        while (p != NULL)
        {
            cout << "NISN: " << p->info.nisn << endl;
            cout << "Nama: " << p->info.nama << endl;
            cout << "Kelas: " << p->info.kelas << endl;
            cout << endl;
            p = p->next;
        }
    }
}