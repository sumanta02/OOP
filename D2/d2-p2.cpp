#include<iostream>
#include<cmath>
using namespace std;

class cal
{
public:
  int Area(int a) {return a * a;}
int Area(int b, int a){return a * b;}
float Area(float a){return (M_PI * a * a);}
};

int main()
{
  cal c;
    int choice = 0;
    while (choice != 4)
    {
        cout <<endl<<"1 -> Calculate area of a square.\n2 -> Calculate area of a square.\n3 -> Calculate area of a circle.\n4 -> Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int a;
            cout << "\nEnter the length of an arm of the square: ";
            cin >> a;
            int area = c.Area(a);
            cout << "\nArea: "<<area<<endl;
            break;
        }
        case 2:
        {
            int a, b;
            cout << "\nEnter the length and width of the rectangle: ";
            cin >> a >> b;
            int area = c.Area(a, b);
            cout << "\nArea: "<<area<<endl;
            break;
        }
        case 3:
        {
            float a;
            cout << "\nEnter the radius of the circle: ";
            cin >> a;
            float area = c.Area(a);
            cout << "\nArea: "<<area<<endl;
            break;
        }
        case 4:
            break;
        default:
            cout << "\nInvalid Input\n";
            break;
        }
    }
}
