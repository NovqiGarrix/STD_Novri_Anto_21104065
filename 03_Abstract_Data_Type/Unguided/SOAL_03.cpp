
/**
 * Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
 */

#include <iostream>

using namespace std;

void printArray(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void swapArray(int arr1[3][3], int arr2[3][3], int pos1, int pos2)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int temp = arr1[i][j];
            arr1[i][j] = arr2[i][j];
            arr2[i][j] = temp;
        }
    }
}

int main()
{
    int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int pos1 = 1;
    int pos2 = 1;

    cout << "Array 1: " << endl;
    printArray(arr1);

    cout << "Array 2: " << endl;
    printArray(arr2);
    cout << endl;

    swapArray(arr1, arr2, pos1, pos2);

    cout << "Array 1 setelah ditukar: " << endl;
    printArray(arr1);
    cout << endl;

    cout << "Array 2 setelah ditukar: " << endl;
    printArray(arr2);
    cout << endl;

    return 0;
}
