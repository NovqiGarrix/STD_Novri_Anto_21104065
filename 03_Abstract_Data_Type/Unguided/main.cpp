#include <iostream>
#include <string>
#include "pelajaran.cpp"

using namespace std;

int main()
{
    string namapel = "Struktur Data";
    string kodepel = "STD";
    Pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    return 0;
}