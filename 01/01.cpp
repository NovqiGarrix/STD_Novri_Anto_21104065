#include <iostream>
using namespace std;

int main()
{
    int x = 5;

    int y = 10;

    int *p1;

    int *p2;

    p1 = &x;

    *p1 = y;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    return 0;
}