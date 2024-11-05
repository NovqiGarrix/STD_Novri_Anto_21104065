#include <iostream>

using namespace std;

struct User
{
    string username;
    string password;
};

typedef User infotype;

typedef struct elmlist *address;

struct elmlist
{
    User data;
    address prev;
    address next;
};

struct DoublyLinkedList
{
    address head;
    address tail;
};

address createNewElm(infotype akun);

void insertLast(DoublyLinkedList &L, address elm);

address findAkun(DoublyLinkedList &L, string username);

void signUp(DoublyLinkedList &L, infotype akun);

void deleteFirst(DoublyLinkedList &L);

void deleteAfter(address p);

void deleteLast(DoublyLinkedList &L);

void removeAkun(DoublyLinkedList &L, string username);