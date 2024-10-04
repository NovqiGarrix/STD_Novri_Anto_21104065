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