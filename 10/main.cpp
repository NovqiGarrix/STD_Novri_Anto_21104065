#include <iostream>

using namespace std;

struct Sale
{
    string name;
    string gol;
};

struct ElmJual
{
    int info;
    ElmJual *next;
};

struct ElmSale
{
    Sale info;
    ElmSale *next;
    ElmJual *next_jual;
};

struct MLL
{
    ElmSale *first;
};

ElmSale *search_sales(MLL list_sales, string nama_sale)
{

    ElmSale *current = list_sales.first;

    while (current != NULL)
    {
        if (nama_sale == current->info.name)
        {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void insert_last_sale(MLL &list_sales, ElmSale *S)
{

    if (list_sales.first == NULL)
    {
        list_sales.first = S;
    }
    else
    {

        list_sales.first->next = S;
    }
}

void create_list(MLL &list_sales)
{
    list_sales.first = NULL;
}

ElmSale *new_elm_sales(Sale info)
{
    ElmSale *S = new ElmSale;
    S->info = info;
    S->next = NULL;
    S->next_jual = NULL;

    return S;
}

ElmJual *new_elm_jual(int info)
{
    ElmJual *J = new ElmJual;
    J->info = info;
    J->next = NULL;

    return J;
}

void insert_new_penjualan(ElmSale *S, ElmJual *J)
{
    ElmJual *last_jual = S->next_jual;

    if (last_jual == NULL)
    {
        S->next_jual = J;
        return;
    }

    while (true)
    {
        if (last_jual->next == NULL)
        {
            break;
        }

        last_jual = last_jual->next;
    }

    last_jual->next = J;
}

void delete_first_penjualan(ElmSale *S)
{
    // Penjualan pertama
    ElmJual *adr_jual = S->next_jual;
    S->next_jual = adr_jual->next;

    delete adr_jual;
}

void show_data_sales(MLL list_sales)
{
    ElmSale *current = list_sales.first;

    while (current != NULL)
    {
        cout << current->info.name << endl;

        ElmJual *current_jual = current->next_jual;

        while (current_jual != NULL)
        {
            cout << current_jual->info << " ";

            current_jual = current_jual->next;
        }

        cout << endl;

        current = current->next;
    }
}

void delete_penjualan(MLL list_sales)
{

    ElmSale *current = list_sales.first;

    while (current != NULL)
    {
        ElmJual *current_jual = current->next_jual;
        ElmJual *prev_current_jual = NULL;

        while (current_jual != NULL)
        {
            if (current_jual->info < 3)
            {
                // Delete it
                if (prev_current_jual != NULL)
                {
                    prev_current_jual->next = current_jual->next;
                    delete current_jual;
                }
            }

            prev_current_jual = current_jual;
            current_jual = current_jual->next;
        }

        current = current->next;
    }
}

int main()
{
    MLL mll;
    create_list(mll);

    Sale *sale = new Sale;
    sale->name = "Siska";
    sale->gol = "Gol A";

    ElmSale *siska = new_elm_sales(*sale);
    ElmJual *siska1 = new_elm_jual(5);
    insert_new_penjualan(siska, siska1);

    ElmJual *siska2 = new_elm_jual(3);
    insert_new_penjualan(siska, siska2);

    ElmJual *siska3 = new_elm_jual(4);
    insert_new_penjualan(siska, siska3);

    ElmJual *siska4 = new_elm_jual(2);
    insert_new_penjualan(siska, siska4);

    insert_last_sale(mll, siska);

    show_data_sales(mll);

    delete_penjualan(mll);

    show_data_sales(mll);

    return 0;
}