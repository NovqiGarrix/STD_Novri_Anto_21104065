#include <iostream>

using namespace std;

int main()
{

  int first, second, third;

  cout << "Masukkan maksimal ukuran array dimensi pertama: " << endl;
  cin >> first;

  cout << "Masukkan maksimal ukuran array dimensi kedua: " << endl;
  cin >> second;

  cout << "Masukkan maksimal ukuran array dimensi ketiga: " << endl;
  cin >> third;

  int arr[first][second][third];

  for (int i = 0; i < first; i++)
  {
    cout << "Dimensi 1 data ke-" << i + 1 << endl;
    cin >> arr[i][0][0];

    for (int j = 0; j < second; j++)
    {
      cout << "Dimensi 2 data ke-" << j + 1 << endl;
      cin >> arr[i][j][0];

      for (int k = 0; k < third; k++)
      {
        cout << "Dimensi 3 data ke-" << k + 1 << endl;
        cin >> arr[i][j][k];
      }
    }
  }
}
