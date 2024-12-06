#include <iostream>

using namespace std;

typedef struct Vertex *adrVertex;
typedef struct Edge *adrEdge;

struct Vertex
{
    char id;
    adrVertex next;
    adrEdge firstEdge;
};

struct Edge
{
    char idVertex;
    int weight;
    adrEdge next;
};

struct Graph
{
    adrVertex first;
};

void createGraph(Graph &G)
{
    G.first = NULL;
}

adrVertex createVertex(char id)
{
    adrVertex P = new Vertex;
    P->id = id;
    P->next = NULL;
    P->firstEdge = NULL;
    return P;
}

adrEdge createEdge(char idVertex, int weight)
{
    adrEdge P = new Edge;
    P->idVertex = idVertex;
    P->weight = weight;
    P->next = NULL;
    return P;
}

void insertVertex(Graph &G, adrVertex P)
{
    adrVertex Q = G.first;
    if (Q == NULL)
    {
        G.first = P;
    }
    else
    {
        while (Q->next != NULL)
        {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertEgde(adrVertex &V, adrEdge P)
{
    adrEdge Q = V->firstEdge;
    if (Q == NULL)
    {
        V->firstEdge = P;
    }
    else
    {
        while (Q->next != NULL)
        {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void printAll(Graph G)
{
    adrVertex P = G.first;
    while (P != NULL)
    {
        cout << P->id << " -> ";
        adrEdge Q = P->firstEdge;
        while (Q != NULL)
        {
            cout << Q->idVertex << " (" << Q->weight << ") -> ";
            Q = Q->next;
        }
        cout << endl;
        P = P->next;
    }
}

int inDegree(Graph G, adrVertex V)
{
    adrVertex P = G.first;
    int count = 0;
    while (P != NULL)
    {
        adrEdge Q = P->firstEdge;
        while (Q != NULL)
        {
            if (Q->idVertex == V->id)
            {
                count++;
            }
            Q = Q->next;
        }
        P = P->next;
    }
    return count;
}

int outDegree(Graph G, adrVertex V)
{
    adrVertex P = G.first;
    int count = 0;
    while (P != NULL)
    {
        if (P->id == V->id)
        {
            adrEdge Q = P->firstEdge;
            while (Q != NULL)
            {
                count++;
                Q = Q->next;
            }

            break;
        }
        P = P->next;
    }
    return count;
}

int degree(Graph G, adrVertex V)
{
    return inDegree(G, V) + outDegree(G, V);
}

bool isSimpleGraph(Graph G)
{
    adrVertex P = G.first;
    while (P != NULL)
    {
        int inD = inDegree(G, P);
        int outD = outDegree(G, P);

        if (inD > 1 || outD > 1)
        {
            return false;
        }

        P = P->next;
    }
    return true;
}

int main()
{

    Graph G;
    createGraph(G);

    adrVertex A = createVertex('A');
    adrVertex B = createVertex('B');
    adrVertex C = createVertex('C');
    adrVertex D = createVertex('D');
    adrVertex E = createVertex('E');

    insertVertex(G, A);
    insertVertex(G, B);
    insertVertex(G, C);
    insertVertex(G, D);
    insertVertex(G, E);

    adrEdge twelve = createEdge('C', 12);
    adrEdge sixty = createEdge('D', 60);
    insertEgde(A, twelve);
    insertEgde(A, sixty);

    adrEdge ten = createEdge('A', 10);
    insertEgde(B, ten);

    adrEdge twenty = createEdge('B', 20);
    adrEdge thirtyTwo = createEdge('D', 32);
    insertEgde(C, twenty);
    insertEgde(C, thirtyTwo);

    adrEdge seven = createEdge('A', 7);
    insertEgde(E, seven);

    printAll(G);

    return 0;
}