#include <iostream>
#include <functional>

using namespace std;

// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

// Inisialisasi
void init()
{
    root = NULL;
}

// Cek Node
bool isEmpty()
{
    return root == NULL;
}

// Buat root
void buatRoot(char data)
{
    if (isEmpty())
    {
        root = new Pohon;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

// Tambah Kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }

    if (node->left != NULL)
    {
        cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }

    baru = new Pohon;
    baru->data = data;
    baru->left = NULL;
    baru->right = NULL;
    baru->parent = node;

    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

// Tambah Kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }

    if (node->right != NULL)
    {
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
    }

    baru = new Pohon;
    baru->data = data;
    baru->left = NULL;
    baru->right = NULL;
    baru->parent = node;

    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

// Ubah Data Tree
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }

    if (!node)
    {
        cout << "\nNode yang ingin diganti tidak ada!" << endl;
        return;
    }

    char temp = node->data;
    node->data = data;
    cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
}

// Lihat Isi Data Tree
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }

    if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }

    cout << "\nData node: " << node->data << endl;
}

// Cari Data Tree
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }

    if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }

    cout << "\nData Node: " << node->data << endl;
    cout << "Root: " << root->data << endl;
    string parent;
    parent = parent + node->parent->data;
    cout << "Parent: " << (node->parent ? parent : "(tidak punya parent)") << endl;

    if (node->parent)
    {
        if (node->parent->left == node && node->parent->right)
            cout << "Sibling: " << node->parent->right->data << endl;
        else if (node->parent->right == node && node->parent->left)
            cout << "Sibling: " << node->parent->left->data << endl;
        else
            cout << "Sibling: (tidak ada sibling)" << endl;
    }
}

void printDescendant(Pohon *node, std::vector<char> &descendants)
{
    if (!node)
    {
        cout << "Node tidak ada!" << endl;
        return;
    }

    if (node->left)
    {
        descendants.push_back(node->left->data);
        printDescendant(node->left, descendants);
    }

    if (node->right)
    {
        descendants.push_back(node->right->data);
        printDescendant(node->right, descendants);
    }
}

void print(std::vector<char> &descendants)
{
    cout << "Descendants: ";
    for (int i = 0; i < descendants.size(); i++)
    {
        cout << descendants[i] << " ";
    }
}

void getDescendants(Pohon *node, std::vector<Pohon *> &descendants)
{
    if (!node)
    {
        cout << "Node tidak ada!" << endl;
        return;
    }

    if (node->left)
    {
        descendants.push_back(node->left);
        getDescendants(node->left, descendants);
    }

    if (node->right)
    {
        descendants.push_back(node->right);
        getDescendants(node->right, descendants);
    }
}

void printAll()
{
    std::vector<Pohon *> descendants;
    getDescendants(root, descendants);

    cout << "Root: " << root->data << endl;

    for (int i = 0; i < descendants.size(); i++)
    {
        cout << "Node " << descendants[i]->data << " adalah descendant dari " << descendants[i]->parent->data << endl;
    }
    cout << endl;
}

void printChild(Pohon *node)
{
    if (!node)
    {
        cout << "Node tidak  ada!" << endl;
    }
    else
    {
        if (node->left)
        {
            cout << "Child kiri: " << node->left->data << endl;
        }

        if (node->right)
        {
            cout << "Child kanan: " << node->right->data << endl;
        }

        if (!node->left && !node->right)
        {
            cout << "Node " << node->data << " tidak memiliki child" << endl;
        }
    }
}

Pohon *findNode(char data)
{

    if (root->data == data)
    {
        return root;
    }

    std::vector<Pohon *> descendants;
    getDescendants(root, descendants);

    Pohon *found = NULL;

    for (int i = 0; i < descendants.size(); i++)
    {
        if (descendants[i]->data == data)
        {
            found = descendants[i];
            break;
        }
    }

    return found;
}

// Fungsi main
int main()
{
    init();
    buatRoot('A');

    while (true)
    {

        cout << "Pilih menu: " << endl;
        cout << "1. Tambah kiri" << endl;
        cout << "2. Tambah kanan" << endl;
        cout << "3. Update node" << endl;
        cout << "4. Lihat descendant" << endl;
        cout << "5. Lihat child" << endl;
        cout << "6. Keluar" << endl;

        cout << endl;
        cout << "Menu: ";
        int menu;
        while (!(cin >> menu))
        {
            cout << "Input harus berupa angka. Silakan coba lagi: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (menu == 1)
        {
            char data;
            cout << "Masukkan data yang ingin ditambah: ";
            cin >> data;

            while (findNode(data) != NULL)
            {
                cout << "Data sudah ada. Tidak bisa menambahkan lagi" << endl;
                cout << "Masukkan kembali data yang ingin ditambah: ";
                cin >> data;
                cout << endl;
                continue;
            }

            printAll();

            char parentNodeChar;
            cout << "Masukkan parent node: ";
            cin >> parentNodeChar;

            Pohon *parentNode = findNode(toupper(parentNodeChar));
            while (parentNode == NULL)
            {
                cout << "Node tidak ditemukan" << endl;
                cout << "Masukkan kembali parent node: ";
                cin >> parentNodeChar;
                parentNode = findNode(toupper(parentNodeChar));
            }

            insertLeft(toupper(data), parentNode);
            cout << "Data berhasil ditambahkan!" << endl;
            cout << endl;

            printAll();
            continue;
        }
        else if (menu == 2)
        {
            char data;
            cout << "Masukkan data yang ingin ditambah: ";
            cin >> data;

            while (findNode(data) != NULL)
            {
                cout << "Data sudah ada. Tidak bisa menambahkan lagi" << endl;
                cout << "Masukkan kembali data yang ingin ditambah: ";
                cin >> data;
                cout << endl;
                continue;
            }

            printAll();

            char parentNodeChar;
            cout << "Masukkan parent node: ";
            cin >> parentNodeChar;

            Pohon *parentNode = findNode(toupper(parentNodeChar));
            while (parentNode == NULL)
            {
                cout << "Node tidak ditemukan" << endl;
                cout << "Masukkan kembali parent node: ";
                cin >> parentNodeChar;
                parentNode = findNode(toupper(parentNodeChar));
            }

            insertRight(toupper(data), parentNode);
            cout << "Data berhasil ditambahkan!" << endl;
            cout << endl;

            printAll();
            continue;
        }
        else if (menu == 3)
        {

            printAll();

            char data;
            cout << "Masukkan data yang ingin diupdate: ";
            cin >> data;

            Pohon *node = findNode(toupper(data));

            while (node == NULL)
            {
                cout << "Node tidak ditemukan" << endl;
                cout << "Masukkan kembali data yang ingin diupdate: ";
                cin >> data;

                cout << endl;

                node = findNode(toupper(data));
                continue;
            }

            char newData;
            cout << "Masukkan data baru: ";
            cin >> newData;

            update(newData, findNode(toupper(data)));

            cout << "Data berhasil diupdate!" << endl;

            continue;
        }
        else if (menu == 4)
        {

            char data;
            cout << "Masukkan parent node: ";
            cin >> data;

            Pohon *node = findNode(toupper(data));

            while (node == NULL)
            {
                cout << "Node tidak ditemukan" << endl;
                cout << "Masukkan kembali parent node: ";
                cin >> data;

                cout << endl;

                node = findNode(toupper(data));
                continue;
            }

            std::vector<char> descendants;
            printDescendant(node, descendants);
            print(descendants);

            cout << endl;
            continue;
        }
        else if (menu == 5)
        {

            char data;
            cout << "Masukkan parent node: ";
            cin >> data;

            Pohon *node = findNode(toupper(data));

            while (node == NULL)
            {
                cout << "Node tidak ditemukan" << endl;
                cout << "Masukkan kembali parent node: ";
                cin >> data;

                cout << endl;

                node = findNode(toupper(data));
                continue;
            }

            printChild(node);

            cout << endl;
            continue;
        }
        else if (menu == 6)
        {
            cout << "Terima kasih!" << endl;
            break;
        }
        else
        {
            cout << "Menu tidak ada!" << endl;
            continue;
        }
    }

    return 0;
}