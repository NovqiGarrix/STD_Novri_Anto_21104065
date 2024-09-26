#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Masukkan angka: ";
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        for (int s = 0; s < n - i; s++)
        {
            cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << j;
        }
        cout << "*";
        for (int k = 1; k <= i; k++)
        {
            cout << k;
        }
        cout << endl;
    }
    for (int s = 0; s < n; s++)
    {
        cout << " ";
    }
    cout << "*" << endl;
    return 0;
}
