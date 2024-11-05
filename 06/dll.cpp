#include <iostream>
#include "dll.h"

using namespace std;

address createNewElm(infotype akun)
{

    address p = new elmlist;
    p->data = akun;
    p->next = NULL;
    p->prev = NULL;

    return p;
}

void insertLast(DoublyLinkedList &L, address elm)
{

    if (L.head == NULL)
    {
        L.head = elm;
        L.tail = elm;
    }
    else
    {
        L.tail->next = elm;
        elm->prev = L.tail;
        elm->next = NULL;
        L.tail = elm;
    }
}

address findAkun(DoublyLinkedList &L, string username)
{
    if (L.head == NULL)
    {
        return NULL;
    }

    address p = L.head;
    while (p != NULL)
    {
        if (p->data.username == username)
        {
            return p;
        }
        p = p->next;
    }

    // Kalau data tidak ditemukan
    return NULL;
}

void signUp(DoublyLinkedList &L, infotype akun)
{
    cout << "Signing up " << akun.username << "..." << endl;
    if (findAkun(L, akun.username) != NULL)
    {
        cout << "Account has been registered." << endl;
    }
    else
    {
        cout << "Account registered." << endl;
        address p = createNewElm(akun);
        insertLast(L, p);
    }
}

void deleteFirst(DoublyLinkedList &L)
{
    if (L.head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        address p = L.head;
        L.head = p->next;
        L.head->prev = NULL;
        delete p;
    }
}

void deleteAfter(address q)
{

    if (q == NULL)
    {
        cout << "Data not found" << endl;
    }
    else if (q->next == NULL)
    {
        cout << "Data is the last data" << endl;
    }
    else if (q->prev == NULL)
    {
        cout << "Data is the last data" << endl;
    }
    else
    {
        address p = q->next;
        q->next = p->next;
        p->next->prev = q;
        delete p;
    }
}

void deleteLast(DoublyLinkedList &L)
{
    address p = L.tail;

    if (L.head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        L.tail = p->prev;
        L.tail->next = NULL;
        delete p;
    }
}

void removeAkun(DoublyLinkedList &L, string username)
{
    if (L.head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        if (findAkun(L, username) == NULL)
        {
            cout << "Data not found" << endl;
        }
        else
        {
            address p = findAkun(L, username);

            // Jika p adalah elemen pertama
            if (L.head == p)
            {
                deleteFirst(L);
            }
            // Jika p adalah elemen terakhir
            else if (p->next == NULL)
            {
                deleteLast(L);
            }
            // Jika p adalah elemen di tengah
            else
            {
                deleteAfter(p->prev);
            }
        }
    }
}