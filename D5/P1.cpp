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
    ~Queue(){delete arr;cout << "\nQueue Destroyed;"};
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
        if (front >= rear)
        {
            front = -1;
            rear = -1;
        }
        front++;
        cout << "\nDequeued Element = " << element << endl;
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

int main()
{
    int choice1 = 0, choice2 = 0, size;
    cout << "\nEnter the size of the queue: ";
    cin >> size;
    Queue<int> intQ(size);
    Queue<float> floatQ(size);
    Queue<char> charQ(size);
    cout << "\nUsing integer array: ";
    intQ.dequeue();
    intQ.enqueue();
    intQ.display();
    intQ.enqueue();
    intQ.display();
    intQ.dequeue();
    intQ.display();
    intQ.dequeue();
    intQ.display();
    cout << "\nUsing float array: ";
    floatQ.dequeue();
    floatQ.enqueue();
    floatQ.display();
    floatQ.enqueue();
    floatQ.display();
    floatQ.dequeue();
    floatQ.display();
    floatQ.dequeue();
    floatQ.display();
    cout << "\nUsing character array: ";
    charQ.dequeue();
    charQ.enqueue();
    charQ.display();
    charQ.enqueue();
    charQ.display();
    charQ.dequeue();
    charQ.display();
    charQ.dequeue();
    charQ.display();
    return 0;
}