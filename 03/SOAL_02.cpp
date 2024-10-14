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

// Create a function to find x in the linked list
adr findElement(List L, infotype x)
{
    adr P = L.first;
    while (P != NULL && P->info != x)
    {
        P = P->next;
    }
    return P;
}

// Create a procedure to remove an element from the linked list
// with the following conditions:
// 1. Check if the list has x element
//    - if it does exist and it is the first element or last element, remove it
//    - if it does exist and it is not the first element or last element, then remove the next element instead (for example if x is 30, then remove 40)
// 2. If the list does not have x element, print "Element not found"

void removeElement(List *L, infotype x)
{
    adr P = L->first;
    adr Prec = NULL;

    while (P != NULL && P->info != x)
    {
        Prec = P;
        P = P->next;
    }

    if (P != NULL)
    {
        if (Prec == NULL)
        {
            L->first = P->next;
            delete P;
        }
        else
        {
            Prec->next = P->next;
            delete P;
        }
    }
    else
    {
        cout << "Element not found" << endl;
    }
}

void printElmt(adr P)
{
    if (P != NULL)
    {
        cout << P->info << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
}

int main()
{

    // a. Create a linked list with 4 nodes
    List *list = new List;
    createEmptyList(list);

    adr elm1 = new ElmtList;
    createElement(elm1, 15);
    insertAscending(list, elm1);

    adr elm2 = new ElmtList;
    createElement(elm2, 30);
    insertAscending(list, elm2);

    adr elm3 = new ElmtList;
    createElement(elm3, 40);
    insertAscending(list, elm3);

    adr elm4 = new ElmtList;
    createElement(elm4, 50);
    insertAscending(list, elm4);

    printList(*list);

    return 0;
}