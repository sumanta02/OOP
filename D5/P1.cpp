#include<iostream>

using namespace std;

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
    ~Queue(){delete arr;cout << "\nQueue Destroyed\n";};
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

int main()
{
    int choice1 = 0, choice2 = 0, size;
    cout << "\nEnter the size of the queue: ";
    cin >> size;
    Queue<int> intQ(size);
    Queue<float> floatQ(size);
    Queue<char> charQ(size);
    while (choice1 != 4)
    {
        cout << "\nUse:\n1 -> Integer Array\n2 -> Float Array\n3 -> Character Array\n4 -> Exit\nEnter Your Choice: ";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            {
                while (choice2 != 4)
                {
                    cout << "\n1 -> Enqueue\n2 -> Dequeue\n3 -> Display\n4 -> Chose Different array\nEnter your choice: ";
                    cin >> choice2;
                    switch (choice2)
                    {
                    case 1:
                        intQ.enqueue();
                        break;
                    case 2:
                        intQ.dequeue();
                        break;
                    case 3:
                        intQ.display();
                        break;
                    case 4:
                        break;
                    default:
                        cout << "\nInvalid Choice\n";
                        break;
                    }
                }
                break;
            }
        case 2:
            {
                while (choice2 != 4)
                {
                    cout << "\n1 -> Enqueue\n2 -> Dequeue\n3 -> Display\n4 -> Chose Different array\nEnter your choice: ";
                    cin >> choice2;
                    switch (choice2)
                    {
                    case 1:
                        floatQ.enqueue();
                        break;
                    case 2:
                        floatQ.dequeue();
                        break;
                    case 3:
                        floatQ.display();
                        break;
                    case 4:
                        break;
                    default:
                        cout << "\nInvalid Choice\n";
                        break;
                    }
                }
                break;
            }
        case 3:
        {
            while (choice2 != 4)
            {
                cout << "\n1 -> Enqueue\n2 -> Dequeue\n3 -> Display\n4 -> Chose Different array\nEnter your choice: ";
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                    charQ.enqueue();
                    break;
                case 2:
                    charQ.dequeue();
                    break;
                case 3:
                    charQ.display();
                    break;
                case 4:
                    break;
                default:
                    cout << "\nInvalid Choice\n";
                    break;
                }
            }
            break;
        }
        default:
            cout << "\nInvalid Choice\n";
            break;
        }
    }
    return 0;
}