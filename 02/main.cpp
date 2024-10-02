#include <iostream>
#include "SLL.cpp"

using namespace std;

int main()
{

    List nL = List();

    // Create list
    Create_List(&nL);

    // Meminta user data pertama yang akan dimasukkan ke list
    string nisn1, nama1, kelas1;

    cout << "Masukkan NISN: ";
    cin >> nisn1;

    cout << "Masukkan Nama: ";
    cin >> nama1;

    cout << "Masukkan Kelas: ";
    cin >> kelas1;

    infotype data1 = Student();
    data1.nisn = nisn1;
    data1.nama = nama1;
    data1.kelas = kelas1;

    // melakukan create new elemen berdasarkan data yang diinputkan user
    adr node1 = New_Element(data1);

    // memanggil salah satu jenis insert (jangan insert after)
    Insert_First(&nL, &node1);

    Show(&nL);
}