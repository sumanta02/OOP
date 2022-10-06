#include<iostream>

using namespace std;

class A
{
    int a;
    public:
        A(int num = 0) : a(num){};
        A operator ++ () {return A(++a);};
        A operator ++ (int) {return A(a++);};
        A operator -- () {return A(--a);};
        A operator -- (int) {return A(a--);};
        friend ostream & operator << (ostream & output, const A & obj)
        {
            output << "\nValue of a: " << obj.a << endl;
            return output;
        }
        friend istream & operator >> (istream & input, A & obj)
        {
            input >> obj.a;
            return input;
        }
};

int main()
{
    A obj1(5), obj2;
    cout << "\nobj1 initialized : " << obj1 << "\nobj2 initialized : " << obj2 << endl;
    cout << "\nobj1++ : " << obj1++ << endl;
    cout << "\nobj1-- : " << obj1-- << endl;
    cout << "\n++obj1 : " << ++obj1 << endl;
    cout << "\n--obj1 : " << --obj1 << endl;
    cout << "\nFinal value of obj1 : " << obj1 << endl;
    cout << "Enter a value: ";
    cin >> obj2;
    cout << "\nobj2 :" << obj2;
    return 0;
}