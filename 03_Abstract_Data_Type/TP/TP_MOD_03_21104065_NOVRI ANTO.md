# Laporan Tugas Pendahuluan

## Cover
Nama    : Novri Anto <br>
NIM     : 21104065 <br>
Judul   : Tugas Pendahuluan Modul 03

## Nomor 1
Jelaskan apa yang dimadsud dengan pointer?
Pointer dalam C++ adalah variable yang menyimpan alamat dari variable lain. 

## Nomor 2
Bagaimana cara menampilkan alamat memori dari suatu variabel dalam program C++? Berikan contoh!

Untuk menampilkan alamat memori dari suatu variabel dalam program C++ kita dapat menggunakan operator `&`. Berikut contoh programnya:

```c++
#include "iostream"

using namespace std;

int main()
{
  int a = 5;
  cout << "Alamat memori dari variabel a adalah: " << &a << endl;
  return 0;
}
```

## Nomor 3
Bagaimana cara menggunakan pointer dalam program C++? Berikan contoh cara menampilkan nilai yang tersimpan pada suatu alamat melalui pointer!

Untuk menggunakan pointer dalam program C++ kita dapat mendeklarasikan pointer dengan menggunakan operator `*`. Berikut contoh programnya:

```c++
#include "iostream"

using namespace std;

int main()
{
  int a = 5;
  int *ptr;
  ptr = &a;
  cout << "Nilai yang tersimpan pada alamat " << ptr << " adalah: " << *ptr << endl;
  return 0;
}
```

## Nomor 4
Jelaskan apa yang dimaksud dengan Abstract Data Type (ADT)!

Abstract Data Type (ADT) adalah tipe data yang didefinisikan oleh sekelompok operasi yang dapat dilakukan pada data tersebut. ADT tidak mendefinisikan algoritma dari operasi-operasi tersebut, hanya mendefinisikan apa saja yang dapat dilakukan oleh operasi tersebut.

## Nomor 5
Berikan contoh ilustrasi sederhana di dalam dunia nyata, tetapi di luar konteks pemrograman!

Sebuah mobil dapat dianggap sebagai contoh dari Abstract Data Type (ADT). Mobil memiliki berbagai operasi yang dapat dilakukan seperti menyalakan mesin, mengemudi, dan berhenti. Namun, mobil tidak mendefinisikan bagaimana mesin bekerja atau bagaimana mobil berhenti, hanya mendefinisikan apa saja yang dapat dilakukan oleh mobil tersebut.

## Nomor 6
Tuliskan ADT dari bangun ruang kerucut dalam bahasa C++!

```c++
#include "iostream"

using namespace std;

class Kerucut
{
private:
    float jari_jari;
    float tinggi;

public:
    Kerucut(float jari_jari, float tinggi)
    {
        this->jari_jari = jari_jari;
        this->tinggi = tinggi;
    }

    float volume()
    {
        return 3.14 * jari_jari * jari_jari * tinggi / 3;
    }
};

int main()
{
    Kerucut kerucut(5, 10);
    cout << "Volume kerucut adalah: " << kerucut.volume() << endl;
    return 0;
}
```