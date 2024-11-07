#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_QUEUE = 5; // Maksimal antrian
int head = -1;
int tail = -1;

struct Mahasiswa
{
    string nama;
    int NIM;
};

struct Node
{
    Mahasiswa data;
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

void enqueueAntrian(LinkedList &L, Mahasiswa data)
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

// Add this comparison function before viewQueue
bool compareNIM(Node *a, Node *b)
{
    return a->data.NIM < b->data.NIM;
}

// Fungsi melihat antrian
void viewQueue(LinkedList L)
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
        return;
    }

    // Create a vector to store the nodes for sorting
    vector<Node *> nodes;
    Node *current = L.head;

    while (current != NULL)
    {
        nodes.push_back(current);
        current = current->next;
    }

    sort(nodes.begin(), nodes.end(), compareNIM);

    cout << "Data antrian teller:" << endl;

    for (size_t i = 0; i < nodes.size(); ++i)
    {
        cout << i + 1 << ". " << nodes[i]->data.nama << " (" << nodes[i]->data.NIM << ")" << endl;
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

    int i = 1;

    while (i <= MAX_QUEUE)
    {
        string name;
        int NIM;

        cout << "Nama Mahasiswa: ";
        getline(cin, name);

        cout << "NIM Mahasiswa: ";
        cin >> NIM;

        cin.ignore();

        Mahasiswa mahasiswa = {name, NIM};
        enqueueAntrian(L, mahasiswa);

        i++;
    }

    viewQueue(L);
    cout << "Jumlah antrian = " << countQueue(L) << endl;
}
