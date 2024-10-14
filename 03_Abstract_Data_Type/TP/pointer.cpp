#include "iostream"

using namespace std;

int main()
{
    // int a = 5;
    // cout << "Alamat memori dari variabel a adalah: " << &a << endl;

    int a = 5;
    int *ptr;
    ptr = &a;
    cout << "Nilai yang tersimpan pada alamat " << ptr << " adalah: " << *ptr << endl;

    return 0;
}