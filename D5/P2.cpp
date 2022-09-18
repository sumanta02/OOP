#include<iostream>
#include"namespace-p1.h"

using namespace std;
using namespace n1;

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
    intQ.dequeue();
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
    floatQ.dequeue();
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
    charQ.dequeue();
    return 0;
}