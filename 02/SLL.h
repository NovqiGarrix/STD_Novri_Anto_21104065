#ifndef SLL_H
#define SLL_H

#include <string>
using std::string;

typedef struct tStudent
{
    string nisn;
    string nama;
    string kelas;
} Student;

typedef Student infotype; // Node data type

typedef struct tElmtList *adr; // Node pointer type

typedef struct tElmtList
{
    infotype info; // Data field
    adr next;      // Pointer to the next node
} ElmtList;

typedef struct
{
    adr first; // Pointer to the first node
} List;

void Create_List(List *L);
adr New_Element(infotype data);
void Insert_First(List *L, adr *p);
void Insert_Last(List *L, adr *p);
void Insert_After(List *L, adr *p, adr *prec);
void Delete_First(List *L, adr *p);
void Delete_Last(List *L, adr *p);
void Delete_After(List *L, adr *prec, adr *p);
void Show(List *L);

#endif
