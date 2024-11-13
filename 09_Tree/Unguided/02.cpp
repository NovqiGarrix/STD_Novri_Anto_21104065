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

bool is_valid_bst(Pohon *node, int min_val, int max_val)
{

    if (node == NULL)
    {
        return true;
    }

    // Periksa apakah node saat ini berada dalam rentang yang valid
    // node saat ini harus harus lebih besar dari nilai minimum
    // dan lebih kecil dari nilai maksimum
    if (node->data < min_val || node->data > max_val)
    {
        return false;
    }

    // valid BST: when the left child is less than the current node
    // and the right child is greater than the current node
    return is_valid_bst(node->left, min_val, node->data) && is_valid_bst(node->right, node->data, max_val);
}

void check(Pohon *node)
{
    if (is_valid_bst(node, INT_MIN, INT_MAX))
    {
        cout << "Valid BST" << endl;
    }
    else
    {
        cout << "Not a valid BST" << endl;
    }
}

int main()
{
    Pohon *root = new Pohon(10);

    // A valid BST
    root->left = new Pohon(4);
    root->left->left = new Pohon(3);
    root->left->right = new Pohon(5);

    root->right = new Pohon(20);
    root->right->left = new Pohon(15);
    root->right->right = new Pohon(21);

    check(root);

    // An invalid BST
    root->left = new Pohon(10);
    root->left->left = new Pohon(5);
    root->left->right = new Pohon(15);
    root->right = new Pohon(20);
    root->right->left = new Pohon(25);
    root->right->right = new Pohon(30);

    check(root);
}