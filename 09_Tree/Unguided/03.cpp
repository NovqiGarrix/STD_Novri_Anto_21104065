#include <iostream>

using namespace std;

struct Pohon
{
    int data;
    Pohon *left;
    Pohon *right;

    Pohon(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int cari_simpul_daun(Pohon *node)
{
    if (node == NULL)
    {
        return 0;
    }

    // Simpul daun ditandai dengan tidak adanya
    // child kiri maupun kanan
    // oleh sebab itu kita me-return 1
    if (node->left == NULL && node->right == NULL)
    {
        return 1;
    }

    // Fungsi ini akan secara rekursif, memeriksa setiap node
    // yang ada pada tree, dan menghitung jumlah simpul daun
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

int main()
{
    Pohon *root = new Pohon(10);

    root->left = new Pohon(4);
    root->left->left = new Pohon(3);
    root->left->right = new Pohon(5);

    root->right = new Pohon(20);
    root->right->left = new Pohon(15);
    root->right->right = new Pohon(21);

    cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << endl;
}