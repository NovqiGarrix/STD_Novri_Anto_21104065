#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node *next;
};

void insertFirst(Node *&head, int data)
{
    Node *newNode = new Node;
    newNode->info = data;
    newNode->next = head;
    head = newNode;
}

void insertLast(Node *&head, int data)
{
    Node *newNode = new Node;
    newNode->info = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
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

void deleteNode(Node *&head, int key)
{
    Node *temp = head;
    Node *prev = NULL;

    if (temp != NULL && temp->info == key)
    {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->info != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return;
    }

    prev->next = temp->next;

    delete temp;
}

int main()
{

    Node *head = NULL;

    insertFirst(head, 10);
    insertLast(head, 20);
    insertFirst(head, 5);

    deleteNode(head, 10);

    printList(head);
}