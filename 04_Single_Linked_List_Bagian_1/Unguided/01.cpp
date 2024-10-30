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

int main()
{

    Node *head = NULL;

    insertFirst(head, 10);
    insertLast(head, 20);
    insertFirst(head, 5);

    printList(head);
}