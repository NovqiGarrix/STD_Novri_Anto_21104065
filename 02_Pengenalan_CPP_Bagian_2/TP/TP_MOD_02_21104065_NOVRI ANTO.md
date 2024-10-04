
# Laporan Tugas Pendahuluan

## Cover
Nama    : Novri Anto <br>
NIM     : 21104065 <br>
Judul   : Tugas Pendahuluan Modul 02

## Hasil Praktikum
### Nomor 1
```c++
#include "iostream"
using namespace std;

int kendaraan(int kapasitas_kendaraan, int jumlah_penumpang)
{
  int jumlah;
  jumlah = jumlah_penumpang / kapasitas_kendaraan;
  if (jumlah_penumpang % kapasitas_kendaraan > 0)
  {
    jumlah++;
  }

  return jumlah;
}

int main()
{
  int kap_kendaraan, jum_penumpang, banyak_kendaraan;
  cout << "Masukkan kapasitas kendaraan: ";
  cin >> kap_kendaraan;
  cout << "Masukkan jumlah penumpang: ";
  cin >> jum_penumpang;
  banyak_kendaraan = kendaraan(kap_kendaraan, jum_penumpang);
  cout << "Banyak kendaraaan yang disewa " << banyak_kendaraan << endl;
  return 0;
}
```

Output:
![Output Nomor 1](<OutputSoal1.png>)

Penjelasan:
Program diatas merupakan program yang digunakan untuk menghitung banyak kendaraan yang disewa berdasarkan kapasitas kendaraan dan jumlah penumpang yang akan dibawa. Program ini menggunakan fungsi kendaraan yang memiliki dua parameter yaitu kapasitas kendaraan dan jumlah penumpang. Fungsi ini akan mengembalikan nilai banyak kendaraan yang disewa, dengan membagi dan memodulasikan jumlah kapasitas kendaraan dengan jumlah penumpang. Program ini akan meminta input kapasitas kendaraan dan jumlah penumpang yang akan diangkut. Kemudian program akan memanggil fungsi kendaraan dan menampilkan banyak kendaraan yang disewa.

### Nomor 2
```c++
#include "iostream"
using namespace std;

void tukar(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main()
{
  int bill, bil2;
  cout << "Masukkan bilangan pertama: ";
  cin >> bill;
  cout << "Masukkan bilangan kedua: ";
  cin >> bil2;
  cout << "Sebelum pertukaran: \n";
  cout << "Bil 1: " << bill << " bil 2: " << bil2 << endl;
  tukar(&bill, &bil2);
  cout << "Setelah pertukaran:\n";
  cout << "Bil 1: " << bill << " bil 2: " << bil2 << endl;

  return 0;
}
```

Output:
![Output Nomor 2](<OutputSoal2.png>)

Penjelasan:
Program diatas merupakan program yang digunakan untuk menukar dua bilangan yang dimasukkan oleh user. Program ini menggunakan fungsi tukar yang memiliki dua parameter pointer. Fungsi ini akan menukar dua bilangan yang dimasukkan oleh user. Program ini akan meminta input dua bilangan dari user. Kemudian program akan memanggil fungsi tukar dan menampilkan dua bilangan yang sudah ditukar.

### Nomor 3
```c++
#include "iostream"
using namespace std;

int main()
{
  int bil[10];
  bil[0] = 1;
  bil[1] = 4;
  bil[2] = 5;
  cout << bil[0] << endl;
  cout << bil[1] << endl;
  cout << bil[2] << endl;
  cout << bil[0] + bil[1] + bil[2] << endl;

  return 0;
}
```

Output:
![Output Nomor 3](<OutputSoal3.png>)

Penjelasan:
Program diatas merupakan program yang digunakan untuk menampilkan isi array bilangan. Program ini akan menampilkan isi array bilangan yang sudah diinisialisasi sebelumnya. Program ini akan menampilkan isi array bilangan pada indeks 0, 1, dan 2. Kemudian program akan menampilkan hasil penjumlahan dari ketiga bilangan tersebut.