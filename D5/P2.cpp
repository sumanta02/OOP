#include<iostream>
#include"namespace-p2.h"

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
