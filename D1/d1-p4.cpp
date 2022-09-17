#include<iostream>

using namespace std;

struct complex
{
    int real, imag;
};

void display (complex obj)
{
    cout <<" \nReal: "<<obj.real<<" Imag: "<<obj.imag<<endl;
};

complex add(complex obj1, complex obj2)
{
    complex a;
    a.real = obj1.real + obj2.real;
    a.imag = obj1.imag + obj2.imag;
    return a;
}
complex subtract(complex obj1, complex obj2)
{
    complex a;
    a.real = obj1.real - obj2.real;
    a.imag = obj1.imag - obj2.imag;
    return a;
}
complex multiply(complex obj1, complex obj2)
{
    int Real = (obj1.real * obj2.real) - (obj1.imag * obj2.imag);
    int Imag = (obj1.real * obj2.imag) + (obj1.imag * obj2.real);
    complex a;
    a.real = Real; 
    a.imag = Imag;
    return a;
}

int main()
{
    complex a, b;
    a.real = 1;
    a.imag = 4;
    b.real = 5;
    b.imag = 1;
    complex c = multiply(a, b);
    display(c);
}