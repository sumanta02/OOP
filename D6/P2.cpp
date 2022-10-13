#include<iostream>

using namespace std;

class A
{
    int a;
    public:
        A(int num = 0) : a(num){};
        A operator ++ () {return A(++a);};
        A operator ++ (int) {return A(a++);};
        friend A operator -- (A &);
        friend A operator -- (A &, int);
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

A operator -- (A & obj)
{
    return A(--obj.a);
}
A operator -- (A & obj, int)
{
    return A(obj.a--);
}

int main()
{
    A obj1(5), obj2 = obj1;
    cout << "\nobj1 initialized : " << obj1 << "\nobj2 initialized : " << obj2 << endl;
    obj2 = obj1++;
    cout << "obj1++\nobj2: " << obj2 << "obj1: " << obj1;
    obj2 = ++obj1;
    cout << "++obj1\nobj2: " << obj2 << "obj1: " << obj1;
    obj2 = obj1--;
    cout << "obj1--\nobj2: " << obj2 << "obj1: " << obj1;
    obj2 = --obj1;
    cout << "--obj1\nobj2: " << obj2 << "obj1: " << obj1;
    return 0;
}