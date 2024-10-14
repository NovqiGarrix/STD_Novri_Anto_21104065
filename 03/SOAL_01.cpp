#include <iostream>
#include "SLL.h"

using namespace std;

// b. Create a procedure to create an empty linked list
void createEmptyList(List *L)
{
    L->first = NULL;
}

// c. Create a function to create a new element
void createElement(ElmtList *P, infotype data)
{
    P->info = data;
    P->next = NULL;
}

// d. Create a procedure called "insertAscending" to insert a new element in an ascending order
void insertAscending(List *L, adr P)
{
    adr Q = L->first;
    adr Prec = NULL;

    while (Q != NULL && P->info > Q->info)
    {
        Prec = Q;
        Q = Q->next;
    }

    if (Prec == NULL)
    {
        P->next = L->first;
        L->first = P;
    }
    else
    {
        P->next = Q;
        Prec->next = P;
    }
}

void printList(List L)
{
    adr P = L.first;
    while (P != NULL)
    {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

int main()
{

    // a. Create a linked list with 4 nodes
    List *list = new List;
    createEmptyList(list);

    adr elm1 = new ElmtList;
    createElement(elm1, 10.5);
    insertAscending(list, elm1);

    adr elm2 = new ElmtList;
    createElement(elm2, 12.0);
    insertAscending(list, elm2);

    adr elm3 = new ElmtList;
    createElement(elm3, 20.9);
    insertAscending(list, elm3);

    adr elm4 = new ElmtList;
    createElement(elm4, 25.1);
    insertAscending(list, elm4);

    printList(*list);

    return 0;
}