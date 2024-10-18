#include <iostream>

using namespace std;

const int IDXMAX = 4;

struct Smartphone
{
    string merk;
    string tipe;
};

struct Stack
{
    Smartphone data[IDXMAX];
    int top;
};

bool isEmpty(Stack S)
{
    return S.top == -1;
}

bool isFull(Stack S)
{
    return S.top == IDXMAX - 1;
}

void push(Stack &S, Smartphone smartphone)
{

    if (isFull(S))
    {
        cerr << "Stack penuh" << endl;
        return;
    }

    S.top++;
    S.data[S.top] = smartphone;
}

Stack createStack()
{
    Stack S;
    S.top = -1;

    return S;
}

void pop(Stack &S)
{
    if (isEmpty(S))
    {
        cerr << "Stack kosong" << endl;
        return;
    }

    S.top--;
}

void printStack(Stack S)
{
    if (isEmpty(S))
    {
        cout << "Stack kosong" << endl;
        return;
    }

    for (int i = S.top; i >= 0; i--)
    {
        cout << "Merk: " << S.data[i].merk << endl;
        cout << "Tipe: " << S.data[i].tipe << endl;
    }
}

int main()
{

    Stack S = createStack();

    Smartphone smartphone1;
    smartphone1.merk = "Samsung";
    smartphone1.tipe = "Galaxy A51";

    push(S, smartphone1);

    // printStack(S);

    Smartphone smartphone2;
    smartphone2.merk = "Xiaomi";
    smartphone2.tipe = "Redmi Note 8";

    push(S, smartphone2);

    // printStack(S);

    Smartphone smartphone3;
    smartphone3.merk = "Oppo";
    smartphone3.tipe = "A9 2020";

    push(S, smartphone3);

    cout << "Sebelum di pop" << endl;
    printStack(S);

    pop(S);

    cout << "================" << endl;
    cout << "Setelah di pop" << endl;
    printStack(S);

    return 0;
}