#include <iostream>
#include "list.cpp"

using namespace std;

int main()
{

    List L;

    // 1. Panggil create list
    createList(&L);

    // // 2. Minta user input
    // int n;

    // cout << "Masukkan data ke-1: ";
    // cin >> n;

    // // 3. Panggil fungsi allocate
    // address nElm = allocate(n);

    // // 4. Panggil insert first
    // insertFirst(L, nElm);

    // // 5. Panggil show info
    // printInfo(L);

    // // 2. Minta user input
    // int o;

    // cout << "Masukkan data ke-2: ";
    // cin >> o;

    // // 3. Panggil fungsi allocate
    // address oElm = allocate(o);

    // // 4. Panggil insert first
    // insertFirst(L, oElm);

    // // 5. Panggil show info
    // printInfo(L);

    // // 2. Minta user input
    // int p;

    // cout << "Masukkan data ke-3: ";
    // cin >> p;

    // // 3. Panggil fungsi allocate
    // address pElm = allocate(p);

    // // 4. Panggil insert first
    // insertFirst(L, pElm);

    // // 5. Panggil show info
    // printInfo(L);

    int total_digit_nim = 10;

    for (int i = 0; i < total_digit_nim; i++)
    {
        int n;

        cout << "Masukkan data ke-" << i + 1 << ": ";
        cin >> n;

        address nElm = allocate(n);

        insertLast(L, nElm);
    }

    printInfo(L);

    return 0;
}