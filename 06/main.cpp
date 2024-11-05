#include <iostream>
#include "dll.cpp"

using namespace std;

int main()
{
    DoublyLinkedList L;
    L.head = NULL;
    L.tail = NULL;

    // Create some sample accounts
    infotype account1 = {"user1", "pass1"};
    infotype account2 = {"user2", "pass2"};
    infotype account3 = {"user3", "pass3"};

    // Sign up new accounts
    cout << "Adding accounts..." << endl;
    signUp(L, account1);
    signUp(L, account2);
    signUp(L, account3);

    // Try to add duplicate account
    cout << "\nTrying to add duplicate account:" << endl;
    signUp(L, account1);

    // Find an account
    cout << "\nSearching for user2:" << endl;
    address found = findAkun(L, "user2");
    if (found != NULL)
    {
        cout << "Found account: " << found->data.username << endl;
    }

    // Remove an account
    cout << "\nRemoving user2..." << endl;
    removeAkun(L, "user2");

    // Try to find the removed account
    cout << "\nSearching for removed user2:" << endl;
    found = findAkun(L, "user2");
    if (found == NULL)
    {
        cout << "Account not found" << endl;
    }

    return 0;
}