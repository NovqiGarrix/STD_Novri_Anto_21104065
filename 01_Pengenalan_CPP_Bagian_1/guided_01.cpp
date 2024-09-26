#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    // Nomor 1
    float bilA;

    float bilB;

    cout << "Bilangan A: " << endl;
    cin >> bilA;

    cout << "Bilangan B: " << endl;
    cin >> bilB;

    // Hasil penjumlahan
    cout << "Hasil penjumlahan: " << bilA + bilB << endl;

    // Hasil pengurangan
    cout << "Hasil pengurangan: " << bilA - bilB << endl;

    // Hasil perkalian
    cout << "Hasil perkalian: " << bilA * bilB << endl;

    // Hasil pembagian
    cout << "Hasil pembagian: " << bilA / bilB << endl;

    return 0;
}