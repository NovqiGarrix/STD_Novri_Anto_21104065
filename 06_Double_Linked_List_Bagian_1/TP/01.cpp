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
    cout << "DAFTAR ANGGOTA LIST: ";
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

int main()
{

    DLL list;
    list.head = NULL;
    list.tail = NULL;

    insertFirst(list, 10);
    insertFirst(list, 5);
    insertLast(list, 20);

    printList(list);
}