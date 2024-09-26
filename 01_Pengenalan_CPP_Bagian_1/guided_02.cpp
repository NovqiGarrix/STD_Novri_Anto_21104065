#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    // Nomor 2
    string angka[] = {"Nol", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh",
                      "Sebelas", "Dua Belas", "Tiga Belas", "Empat Belas", "Lima Belas", "Enam Belas", "Tujuh Belas", "Delapan Belas", "Sembilan Belas", "Dua Puluh",
                      "Tiga Puluh", "Empat Puluh", "Lima Puluh", "Enam Puluh", "Tujuh Puluh", "Delapan Puluh", "Sembilan Puluh"};

    string seratus = "Seratus";

    int num;
    cout << "Masukkan angka (0-100): ";
    cin >> num;

    if (num < 0 || num > 100)
    {
        cout << "Angka harus antara 0 dan 100." << endl;
    }
    else if (num <= 20)
    {
        cout << angka[num] << endl;
    }
    else if (num < 100)
    {
        int puluhan = num / 10;
        int satuan = num % 10;
        if (satuan == 0)
        {
            cout << angka[18 + puluhan] << endl;
        }
        else
        {
            cout << angka[18 + puluhan] << " " << angka[satuan] << endl;
        }
    }
    else
    {
        cout << seratus << endl;
    }

    return 0;
}