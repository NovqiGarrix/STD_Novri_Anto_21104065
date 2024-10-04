#include <iostream>

using namespace std;

int main()
{

    int max;

    cout << "Masukkan jumlah data: " << endl;
    cin >> max;

    int arr[max];

    for (int i = 0; i < max; i++)
    {
        cout << "Data ke-" << i + 1 << endl;
        cin >> arr[i];
    }

    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Cari nilai maksimum\n";
        cout << "2. Cari nilai minimum\n";
        cout << "3. Hitung rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int maxVal = arr[0];
            for (int i = 1; i < max; i++)
            {
                if (arr[i] > maxVal)
                {
                    maxVal = arr[i];
                }
            }
            cout << "Nilai maksimum: " << maxVal << endl;
            break;
        }
        case 2:
        {
            int minVal = arr[0];
            for (int i = 1; i < max; i++)
            {
                if (arr[i] < minVal)
                {
                    minVal = arr[i];
                }
            }
            cout << "Nilai minimum: " << minVal << endl;
            break;
        }
        case 3:
        {
            int sum = 0;
            for (int i = 0; i < max; i++)
            {
                sum += arr[i];
            }
            double average = static_cast<double>(sum) / max;
            cout << "Rata-rata: " << average << endl;
            break;
        }
        case 4:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Opsi tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 4);
}