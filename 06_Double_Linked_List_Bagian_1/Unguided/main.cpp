#include <iostream>

using namespace std;

struct Book
{
    int id;
    string judul;
    string penulis;
};

struct Node
{
    Book data;
    Node *prev;
    Node *next;
};

struct DoubleLinkedList
{
    Node *head;
    Node *tail;
    int size;
};

void insertLast(DoubleLinkedList &list, Book data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (list.head == NULL)
    {
        list.head = newNode;
        list.tail = newNode;
        newNode->prev = NULL;
    }
    else
    {
        list.tail->next = newNode;
        newNode->prev = list.tail;
        list.tail = newNode;
    }

    list.size++;
}

void showHeadThroughTail(DoubleLinkedList list)
{
    Node *temp = list.head;
    while (temp != NULL)
    {
        cout << "ID: " << temp->data.id << endl;
        cout << "Judul: " << temp->data.judul << endl;
        cout << "Penulis: " << temp->data.penulis << endl;
        cout << "------------------------" << endl;
        temp = temp->next;
    }
    cout << endl;
}

void showTailThroughHead(DoubleLinkedList list)
{
    Node *temp = list.tail;
    while (temp != NULL)
    {
        cout << "ID: " << temp->data.id << endl;
        cout << "Judul: " << temp->data.judul << endl;
        cout << "Penulis: " << temp->data.penulis << endl;
        cout << "------------------------" << endl;
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{

    // Initialize Double Linked List
    DoubleLinkedList bookList;
    bookList.head = NULL;
    bookList.tail = NULL;
    bookList.size = 0;

    // Create and insert sample books
    Book book1 = {1, "The Great Gatsby", "F. Scott Fitzgerald"};
    Book book2 = {2, "To Kill a Mockingbird", "Harper Lee"};
    Book book3 = {3, "1984", "George Orwell"};
    Book book4 = {4, "Pride and Prejudice", "Jane Austen"};
    Book book5 = {5, "The Catcher in the Rye", "J.D. Salinger"};

    insertLast(bookList, book1);
    insertLast(bookList, book2);
    insertLast(bookList, book3);
    insertLast(bookList, book4);
    insertLast(bookList, book5);

    // Show books from head to tail
    showHeadThroughTail(bookList);

    // Show books from tail to head
    showTailThroughHead(bookList);
}