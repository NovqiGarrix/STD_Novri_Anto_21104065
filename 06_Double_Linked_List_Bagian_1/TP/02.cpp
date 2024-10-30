#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

struct DLL
{
    Node *head;
    Node *tail;
};

void insertFirst(DLL &list, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = list.head;
    newNode->prev = NULL;

    if (list.head == NULL)
    {
        list.head = newNode;
        list.tail = newNode;
    }
    else
    {
        list.head->prev = newNode;
        list.head = newNode;
    }
}

void insertLast(DLL &list, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list.tail;

    if (list.head == NULL)
    {
        list.head = newNode;
        list.tail = newNode;
    }
    else
    {
        list.tail->next = newNode;
        list.tail = newNode;
    }
}

void printList(DLL list)
{
    cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: ";
    Node *current = list.head;
    while (current != NULL)
    {
        cout << current->data;
        if (current->next != NULL)
        {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << endl;
}

void deleteFirst(DLL &list)
{
    if (list.head != NULL)
    {
        Node *temp = list.head;
        list.head = list.head->next;
        list.head->prev = NULL;
        delete temp;
    }
}

void deleteLast(DLL &list)
{
    if (list.head != NULL)
    {
        Node *temp = list.tail;
        list.tail = list.tail->prev;
        list.tail->next = NULL;
        delete temp;
    }
}

int main()
{
    DLL list;
    list.head = NULL;
    list.tail = NULL;

    insertFirst(list, 10);
    insertLast(list, 15);
    insertLast(list, 20);

    deleteFirst(list);
    deleteLast(list);

    printList(list);
}