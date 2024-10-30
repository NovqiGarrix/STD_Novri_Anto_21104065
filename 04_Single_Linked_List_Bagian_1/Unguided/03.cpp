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

bool findNode(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->info == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int getLength(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

int main()
{

    Node *head = NULL;

    insertFirst(head, 10);
    insertLast(head, 20);
    insertFirst(head, 5);

    if (findNode(head, 20))
    {
        cout << "Node dengan nilai 20 ditemukan" << endl;
    }
    else
    {
        cout << "Node not found" << endl;
    }

    cout << "Panjang linked list: " << getLength(head) << endl;
}