#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node *next;
};

struct List
{
    Node *head;
};

void insertSorted_21104065(List &L, int x)
{
    Node *newNode = new Node;
    newNode->info = x;
    newNode->next = NULL;

    if (L.head == NULL)
    {
        L.head = newNode;
    }
    else if (x < L.head->info)
    {
        newNode->next = L.head;
        L.head = newNode;
    }
    else
    {
        Node *temp = L.head;
        while (temp->next != NULL && temp->next->info < x)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    List L;
    L.head = NULL;

    int t = 4;

    for (int i = 0; i < t; i++)
    {
        int y;
        cout << "Masukkan angka ke-" << i + 1 << ": ";
        cin >> y;
        insertSorted_21104065(L, y);
    }

    printList(L.head);

    return 0;
}