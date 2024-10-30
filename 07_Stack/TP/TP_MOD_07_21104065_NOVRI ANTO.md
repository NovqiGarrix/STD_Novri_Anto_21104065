# Laporan Tugas Pendahuluan

## Cover
Nama    : Novri Anto <br>
NIM     : 21104065 <br>
Judul   : Tugas Pendahuluan Modul 07

```c++
// stack.h

typedef char infotype;

struct stack
{
    infotype info[15];
    int Top;
};

void createStack(stack &S);

bool isEmpty(stack S);

bool isFull(stack S);

void push(stack &S, infotype x);

int pop(stack &S);

void printInfo(stack S);
```

```c++
// stack.cpp
#include "stack.h"
#include <iostream>

void createStack(stack &S)
{
    S.Top = -1;
}

bool isEmpty(stack S)
{
    if (S.Top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(stack S)
{
    if (S.Top == 14)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(stack &S, infotype x)
{
    if (!isFull(S))
    {
        S.Top++;
        S.info[S.Top] = x;
    }
    else
    {
        std::cout << "Stack sudah penuh" << std::endl;
    }
}

int pop(stack &S)
{
    if (!isEmpty(S))
    {
        int x = S.info[S.Top];
        S.Top--;
        return x;
    }
    else
    {
        std::cout << "Stack kosong tidak bisa menghapus elemen" << std::endl;
        return -1; // -1 adalah nilai yang tidak mungkin ada di stack
    }
}

void printInfo(stack S)
{
    for (int i = S.Top; i >= 0; i--)
    {
        std::cout << S.info[i] << " ";
    }
    std::cout << std::endl;
}
```

### Expected Input/Output
NIM: 21104065
Digit terakhir NIM: 5

NIM % 4 sisa 1

Output yang diharapkan:
H A L O B A N D U N G
B A N D U N G

```c++
// main.cpp
#include <iostream>
#include "stack.cpp"

int main()
{

    std::string word;

    std::cout << "Input: ";
    std::getline(std::cin, word);

    stack S;
    createStack(S);

    for (int i = 0; i < word.length(); i++)
    {
        push(S, word[i]);
    }

    printInfo(S);

    pop(S);
    pop(S);
    pop(S);
    pop(S);

    printInfo(S);
}
```

### Output
![Output](<Output.png>)