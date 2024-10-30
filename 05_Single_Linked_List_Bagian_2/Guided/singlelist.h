#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList
{
    infotype info;
    address next;
};

struct List
{
    address First;
};

// Create an empty list
void CreateList(List &L);

// Allocate new element with data x
address alokasi(infotype x);

// Deallocate element pointed by P
void dealokasi(address &P);

// Print all elements in the list
void printInfo(List L);

// Insert element P at the beginning of list L
void insertFirst(List &L, address P);

address findElm(List L, infotype x);

#endif