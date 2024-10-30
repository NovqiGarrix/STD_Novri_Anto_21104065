#include <iostream>

using namespace std;

const int MAX = 1000; // maksimal data yang bisa dimasukkan ke stack
int myStack[MAX];     // stack
int top = -1;         // inisialisasi nilai top. -1 artinya blm ada data yg dimasukkan ke stack. Top adalah index array dari variabel top

// fungsi untuk mengecek apakah stack kosong
bool isEmpty()
{
    return top == -1; // jika top == -1, maka stack kosong
}

// fungsi untuk mengecek apakah stack penuh
bool isFull()
{
    return top == MAX - 1; // jika top == MAX - 1, maka stack penuh. MAX - 1 karena index array dimulai dari 0
}

// fungsi untuk memasukkan data ke stack
void push(int value)
{
    // Periksa apakah stack penuh
    // sebelum memasukkan data
    if (isFull())
    {
        // Stack penuh tampilkan pesan error
        cout << "Stack sudah penuh" << endl;
        return;
    }

    // Jika stack tidak penuh,
    // tambahkan data ke stack
    myStack[++top] = value;
}

// fungsi untuk mengeluarkan data dari stack
// dan mengembalikan nilainya
int pop()
{
    // Periksa apakah stack kosong
    if (isEmpty())
    {
        // Jika stack kosong tampilkan pesan error
        // karena tidak bisa mengeluarkan data dari stack kosong
        cout << "Stack sudah kosong" << endl;
        return -1;
    }

    // Stack tidak kosong,
    // keluarkan data dari stack
    // dan kembalikan nilainya
    return myStack[top--];
}

// fungsi untuk membalikkan kalimat
void reverseWord(const string &str)
{
    // Loop setiap karakter dari kata/kalimat
    for (int i = 0; i < str.length(); i++)
    {
        // lalu masukkan setiap karakter ke dalam stack
        push(str[i]);
    }

    cout << "Kalimat terbalik: ";
    // Loop setiap karakter dari stack
    // sampai stack kosong
    while (!isEmpty())
    {
        // lalu keluarkan setiap karakter dari stack
        // dan tampilkan karakter tersebut.
        // Pop mengambil data terakhir yang dimasukkan ke stack
        // lalu mengembalikan nilainya
        cout << (char)pop();
    }

    cout << endl;
}

int main()
{
    // Inisialisasi variabel untuk menampung kata/kalimat
    string word;

    cout << "Masukkan kalimat: ";
    // Masukkan data yang diinputkan user ke variabel word
    getline(cin, word);

    // Periksa apakah panjang kata/kalimat sampai 3 huruf
    // jika kurang dari 3 huruf, tampilkan pesan error
    if (word.length() < 3)
    {
        cout << "Kalimat minimal 3 huruf" << endl;
        return 0;
    }

    // Panggil fungsi reverseWord
    // untuk membalikkan kata/kalimat
    reverseWord(word);

    return 0;
}