#include <iostream>

using namespace std;

const int MAX_QUEUE = 5; // Maksimal antrian
int head = -1;
int tail = -1;
// string queueTeller[5];       // Fungsi pengecekan

struct Node
{
    string data;
    Node *next;
};

struct LinkedList
{
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
};

bool isFull()
{
    return tail == MAX_QUEUE - 1;
}

bool isEmpty()
{
    return head == -1 && tail == -1;
}

void enqueueAntrian(LinkedList &L, string data)
{

    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {

        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (isEmpty())
        {
            L.head = newNode;
            L.tail = newNode;
            head++;
        }

        tail += 1;
        L.tail->next = newNode;
        L.tail = newNode;
    }
}

void dequeueAntrian(LinkedList &L)
{

    if (isEmpty())
    {
        cout << "Tidak ada data yang di dequeue" << endl;
        return;
    }

    Node *temp = L.head;
    L.head = L.head->next;
    head++;

    if (L.head == NULL)
    {
        head = -1;
        tail = -1;
        cout << "Antrian sudah kosong. Reset!" << endl;
    }

    delete temp;
}

// Fungsi menghitung banyak antrian
int countQueue(LinkedList L)
{
    if (isEmpty())
    {
        return 0;
    }

    int i = 0;
    Node *current = L.head;

    while (current != NULL)
    {
        i++;
        current = current->next;
    }

    return i;
}

// Fungsi melihat antrian
void viewQueue(LinkedList L)
{

    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
        return;
    }

    cout << "Data antrian teller:" << endl;

    Node *current = L.head;
    int i = 1;

    while (current != NULL)
    {
        cout << i << ". " << current->data << " " << endl;
        current = current->next;
        i++;
    }
}

void clearQueue(LinkedList &L)
{
    head = -1;
    tail = -1;

    L.head = NULL;
    L.tail = NULL;
}

int main()
{

    LinkedList L;

    enqueueAntrian(L, "Andi");
    enqueueAntrian(L, "Maya");
    viewQueue(L);
    cout << "Jumlah antrian = " << countQueue(L) << endl;
    dequeueAntrian(L);
    viewQueue(L);
    cout << "Jumlah antrian = " << countQueue(L) << endl;
    clearQueue(L);
    viewQueue(L);
    cout << "Jumlah antrian = " << countQueue(L) << endl;
    return 0;
}
