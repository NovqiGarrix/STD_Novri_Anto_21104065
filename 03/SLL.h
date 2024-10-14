typedef float Element;

typedef Element infotype; // Node data type

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