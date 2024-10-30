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

void searchElement_21104065(Node *head, int x)
{
    Node *current = head;
    int position = 1;
    bool found = false;

    while (current != NULL)
    {
        if (current->info == x)
        {
            cout << "Data " << x << " ditemukan pada posisi " << position;
            cout << "\nAddress: " << current << endl;
            found = true;
            break;
        }
        current = current->next;
        position++;
    }

    if (!found)
    {
        cout << "Data " << x << " tidak ditemukan di dalam list" << endl;
    }
}

int main()
{

    List L;
    L.head = NULL;

    int t;

    cout << "Masukkan angka: ";
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int y;
        cout << "Masukkan angka ke-" << i + 1 << ": ";
        cin >> y;
        insertLast_21104065(L.head, y);
    }

    int x;
    cout << "Masukkan angka yang ingin dicari: ";
    cin >> x;

    searchElement_21104065(L.head, x);

    return 0;
}