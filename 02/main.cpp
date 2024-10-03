#include "SLL.cpp"
#include "SLL.h"
#include <iostream>

using namespace std;

int main() {

  List nL = List();

  // Create list
  Create_List(&nL);

  cout << "----- Memasukkan data pertama ------" << endl;

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

  cout << "----- Memasukkan data kedua ------" << endl;

  // Meminta user data kedua yang akan dimasukkan ke list
  string nisn2, nama2, kelas2;

  cout << "Masukkan NISN: ";
  cin >> nisn2;

  cout << "Masukkan Nama: ";
  cin >> nama2;

  cout << "Masukkan Kelas: ";
  cin >> kelas2;

  infotype data2 = Student();
  data2.nisn = nisn2;
  data2.nama = nama2;
  data2.kelas = kelas2;

  // melakukan create new elemen berdasarkan data yang diinputkan user
  adr node2 = New_Element(data2);

  // Memanggil salah satu jenis insert (berbeda dengan insert yang data pertama,
  // jangan Insert after)
  Insert_Last(&nL, &node2);

  cout << "----- Memasukkan data ketiga ------" << endl;

  // Meminta user data ketiga yang akan dimasukkan ke list
  string nisn3, nama3, kelas3;

  cout << "Masukkan NISN: ";
  cin >> nisn3;

  cout << "Masukkan Nama: ";
  cin >> nama3;

  cout << "Masukkan Kelas: ";
  cin >> kelas3;

  infotype data3 = Student();
  data3.nisn = nisn3;
  data3.nama = nama3;
  data3.kelas = kelas3;

  // melakukan create new elemen berdasarkan data yang diinputkan user
  adr node3 = New_Element(data3);

  // Memanggil salah satu jenis insert (insert First)
  Insert_First(&nL, &node3);

  cout << "----- Memasukkan data keempat ------" << endl;

  // Meminta user data pertama yang akan dimasukkan ke list
  string nisn4, nama4, kelas4;

  cout << "Masukkan NISN: ";
  cin >> nisn4;

  cout << "Masukkan Nama: ";
  cin >> nama4;

  cout << "Masukkan Kelas: ";
  cin >> kelas4;

  infotype data4 = Student();
  data4.nisn = nisn4;
  data4.nama = nama4;
  data4.kelas = kelas4;

  // melakukan create new elemen berdasarkan data yang diinputkan user
  adr node4 = New_Element(data4);

  // memanggil salah satu jenis insert (insert last)
  Insert_Last(&nL, &node4);

  Show(&nL);

  // Melakukan penghapusan data dengan memanfaatkan salah satu jenis delete
  // (bukan delete after)
  Delete_First(&nL, &node3);

  // melakukan penghapusan data dengan memanfaatkan salah satu jenis delete
  // (berbede dengan delete sebelumnya, dan bukan delete after)
  Delete_Last(&nL, &node4);

  return 0;
}
