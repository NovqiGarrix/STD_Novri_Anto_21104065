#include <iostream>

using namespace std;

class Antrian
{
private:
    int head = -1;
    int tail = -1;
    int antrian[5];
    int MAX = 5;

public:
    bool isFull()
    {
        // Check if the tail is equal to the maximum index
        return tail == MAX - 1;
    }

    bool isEmpty()
    {
        // cout << "head: " << head << " tail: " << tail << endl;
        // Check if the head and tail is -1 or using the default value
        return head == -1 && tail == -1;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Antrian sudah penuh" << endl;
        }
        else
        {
            if (isEmpty())
            {
                head = 0;
            }

            tail++;
            antrian[tail] = value;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Tidak ada elemen dalam antrian" << endl;
        }

        head++;

        // Check if the head is greater than tail
        // this is to check if the queue is empty
        // cout << "head: " << head << " tail: " << tail << endl;
        if (head > tail)
        {
            // so that
            // the head and tail can be reset to the default value
            // and start from the beginning
            head = -1;
            tail = -1;
        }
    }

    void printQueue()
    {
        if (!isEmpty())
        {
            for (int i = head; i <= tail; i++)
            {
                cout << i << ": " << antrian[i] << " ";
            }
        }
    }
};

int main()
{
    Antrian antrian = Antrian();

    cout << "isEmpty: " << antrian.isEmpty() << endl;
    cout << "isFull: " << antrian.isFull() << endl;

    antrian.enqueue(1);

    cout << "isEmpty: " << antrian.isEmpty() << endl;

    antrian.enqueue(20);
    antrian.enqueue(300);
    antrian.enqueue(4000);
    antrian.enqueue(5000);

    cout << "isFull: " << antrian.isFull() << endl;

    antrian.dequeue();

    cout << "isFull: " << antrian.isFull() << endl;
    antrian.printQueue();

    antrian.dequeue();
    antrian.dequeue();
    antrian.dequeue();
    antrian.dequeue();

    // Error because the queue is empty
    antrian.dequeue();
}