#include<iostream>
using namespace std;

namespace n1
{
    template <class T>
    class Queue
    {
        int count, front, rear;
        T *arr;
        public:
        Queue(int c = 0):count(c), front(-1), rear(-1){arr = new T[count];cout << "queue of size " << count << " created.\n";};
        void enqueue();
        void dequeue();
        void display();
        ~Queue(){delete arr;cout << "\nQueue Destroyed;\n";};
    };

    template <class T>
    void Queue<T>::enqueue()
    {
        T input;
        cout << "\nEnter value to enter into Queue: ";
        cin >> input;
        if (rear == count - 1 && front == 0)
            cout << "\nQueue Overflow.\n";
        else
        {
            if (front == -1)    front++;
            arr[++rear] = input;
            cout << "\nEnqueued Element = " << input << endl;
        }
        return;
    };

    template <class T>
    void Queue<T>::dequeue()
    {
        T element;
    if (front == -1)
        cout << "\nQueue Underflow.\n";
    else
    {
        element = arr[front];
        cout << "\nDequeued Element = " << element << endl;
        front++;
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
    };

    template <class T>
    void Queue<T>::display()
    {
        if (front == -1)
            cout << "\nQueue Underflow.\n";
        else if (rear == count - 1 && front == 0)
            cout << "\nQueue Overflow.\n";
        else
        {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << "  ";
            }
            cout << endl;
        }
    };
}