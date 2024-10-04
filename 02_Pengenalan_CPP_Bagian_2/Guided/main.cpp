#include "iostream"
#include "stdlib.h"

#define MAX 5
using namespace std;

int max3(int a, int b, int c);
void tulis(int x);
// void tukar(int x, int y);
// void tukar(int &x, int &y);
void tukar(int *x, int *y);

int main() {

  // char a;
  // int j;
  // char arr[6];
  // arr[3] = 'b';
  // a = 'u';

  // cout << a << endl;
  // cout << &a << endl;
  // cout << j << endl;
  // cout << &j << endl;
  // cout << &(arr[4]) << endl;

  // int x, y; // x dan y bertipe int
  // int *px;  // px merupakan variabel pointer menunjuk ke variabel int x =87;
  // px = &x;
  // y = *px;
  // cout << "Alamat x= " << &x << endl;
  // cout << "Isi px= " << px << endl;
  // cout << "Isi X= " << x << endl;
  // cout << "Nilai yang ditunjuk px= " << *px << endl;
  // cout << "Nilai y= " << y << endl;

  int i, j;
  float nilai_total, rata_rata;
  float nilai[MAX];

  static int nilai_tahun[MAX][MAX] = {{0, 2, 2, 0, 0},
                                      {0, 1, 1, 1, 0},
                                      {0, 3, 3, 3, 0},
                                      {4, 4, 0, 0, 4},
                                      {5, 0, 0, 0, 5}};

  // inisialisasi array dua dimensi
  for (i = 0; i < MAX; i++) {
    cout << "Masukkan nilai ke-1: " << i + 1 << endl;
    cin >> nilai[i];
  }

  cout << "\n Data nilai siswa: \n" << endl;

  // Menampilkan array satu dimensi
  for (i = 0; i < MAX; i++) {
    cout << "Nilai ke-" << i + 1 << " = " << nilai[i] << endl;

    cout << "\n Nilai tahunan: \n" << endl;
    // Menampilkan array dua dimensi
    for (j = 0; j < MAX; j++) {
      cout << nilai_tahun[i][j] << endl;
      cout << "\n" << endl;
    }
  }

  int x, y, z;
  cout << "Masukkan bilangan pertama: " << endl;
  cin >> x;

  cout << "Masukkan bilangan kedua: " << endl;
  cin >> y;

  cout << "Masukkan bilangan ketiga: " << endl;
  cin >> z;

  int max_result = max3(x, y, z);
  cout << "Bilangan yang paling besar adalah: " << max_result << endl;

  int max_word_rows;

  cout << "Masukkan jumlah baris kata: " << endl;
  cin >> max_word_rows;

  tulis(max_word_rows);

  int first_int, second_int;
  cout << "Masukkan bilangan pertama: " << endl;
  cin >> first_int;

  cout << "Masukkan bilangan kedua: " << endl;
  cin >> second_int;

  cout << "Bilangan sebelum ditukar: " << endl;
  cout << "Bil 1: " << first_int << "\n Bil 2: " << second_int << endl;

  tukar(&first_int, &second_int);

  return 0;
}

int max3(int a, int b, int c) {
  int temp_max = a;
  if (b > temp_max) {
    temp_max = b;
  }

  if (c > temp_max) {
    temp_max = c;
  }

  return temp_max;
}

void tulis(int x) {
  for (int i = 0; i < x; i++) {
    cout << "Baris ke-" << i + 1 << endl;
  }
}

// void tukar(int x, int y) {
//   int temp = x;
//   x = y;
//   y = temp;
//
//   cout << "\n x = " << x << endl;
//   cout << "y = " << y << "\n" << endl;
// }

// void tukar(int &x, int &y) {
//   int temp = x;
//   x = y;
//   y = temp;
//
//   cout << "\n x = " << x << endl;
//   cout << "y = " << y << "\n" << endl;
// }

void tukar(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = *temp;

  cout << "\n x = " << x << endl;
  cout << "y = " << y << "\n" << endl;
}
