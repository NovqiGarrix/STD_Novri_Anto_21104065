#include <iostream>
#include <string>

using namespace std;

int main() {

  int max;
  cout << "Input jumlah maksimal: " << endl;
  cin >> max;

  int numbers[max];
  string compound_numbers;
  string genap;
  string ganjil;

  for (int i = 0; i < max; i++) {
    cout << "Masukkan data ke-" << i + 1 << ": " << endl;
    cin >> numbers[i];
    compound_numbers += " " + to_string(numbers[i]);
    if (numbers[i] % 2 == 0) {
      genap += " " + to_string(numbers[i]);
    } else {
      ganjil += " " + to_string(numbers[i]);
    }
  }

  cout << "Data array: " << compound_numbers << endl;
  cout << "Data genap: " << genap << endl;
  cout << "Data ganjil: " << ganjil << endl;
}
