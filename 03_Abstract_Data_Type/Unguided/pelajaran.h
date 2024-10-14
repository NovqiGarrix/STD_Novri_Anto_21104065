#include <string>

using namespace std;

typedef struct Pelajaran
{
    string namaMapel;
    string kodeMapel;
} Pelajaran;

Pelajaran create_pelajaran(string namaMapel, string kodeMapel);
void tampil_pelajaran(Pelajaran pelajaran);
