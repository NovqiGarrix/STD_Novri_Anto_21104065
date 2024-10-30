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

// fungsi untuk mengecek apakah kalimat palindrome
// const itu artinya parameter str tidak bisa diubah nilainya
bool isPalindrome(const string &str)
{
    // Loop setiap karakter dari kata/kalimat
    int length = str.length();
    for (int i = 0; i < length / 2; i++)
    {
        // Periksa apakah karakter pertama dari variabel str sama dengan karakter terakhir dari stack
        // jika tidak sama, maka bukan palindrome
        if (str[i] != pop())
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string word;

    // Inisialisasi variabel untuk menampung kata/kalimat
    string word;

    cout << "Masukkan kalimat: ";
    // Masukkan data yang diinputkan user ke variabel word
    getline(cin, word);

    // Masukkan setiap karakter dari intputan user ke dalam stack
    for (int i = 0; i < word.length(); i++)
    {
        push(word[i]);
    }

    // Periksa apakah kalimat tersebut palindrome
    // dan tampilkan hasilnya
    cout << "Kalimat tersebut adalah " << (isPalindrome(word) ? "palindrome" : "bukan palindrome") << endl;

    return 0;
}