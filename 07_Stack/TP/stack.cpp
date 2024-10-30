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