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