#include <iostream>
#include <string>
#include "pelajaran.h"

using namespace std;

Pelajaran create_pelajaran(string namaMapel, string kodeMapel)
{
    Pelajaran pelajaran;
    pelajaran.namaMapel = namaMapel;
    pelajaran.kodeMapel = kodeMapel;

    return pelajaran;
}

void tampil_pelajaran(Pelajaran pelajaran)
{
    cout << "Nama Mapel: " << pelajaran.namaMapel << endl;
    cout << "Kode Mapel: " << pelajaran.kodeMapel << endl;
}