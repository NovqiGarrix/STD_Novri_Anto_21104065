#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node *next;
};

void insertFirst_21104065(Node *&head, int info)
{
    Node *newNode = new Node;
    newNode->info = info;
    newNode->next = head;
    head = newNode;
}

void insertLast_21104065(Node *&head, int info)
{
    Node *newNode = new Node;
    newNode->info = info;
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

struct List
{
    Node *head;
};

void bubbleSort_21104065(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    bool swapped;
    Node *current;
    do
    {
        swapped = false;
        current = head;

        while (current->next != NULL)
        {
            if (current->info > current->next->info)
            {
                int temp = current->info;
                current->info = current->next->info;
                current->next->info = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
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

    int t = 5;

    for (int i = 0; i < t; i++)
    {
        int y;
        cout << "Masukkan angka ke-" << i + 1 << ": ";
        cin >> y;
        insertLast_21104065(L.head, y);
    }

    bubbleSort_21104065(L.head);

    printList(L.head);

    return 0;
}