#include<iostream>

using namespace std;

class complex
{
    int real, imag;
    public:
    complex(int a = 0, int b = 0): real(a), imag(b){};
    complex add(complex obj);
    complex subtract(complex obj);
    complex multiply(complex obj);
    inline void display ()
    {
            cout <<"\nReal coeff: "<<real<<" imaginary coeff: "<<" "<<imag<<"i\n";
    };
};

    complex complex::add(complex obj)
    {
        complex a(real + obj.real, imag + obj.imag);
        return a;
    }
    complex complex::subtract(complex obj)
    {
        complex a(real - obj.real, imag - obj.imag);
        return a;
    }
    complex complex::multiply(complex obj)
    {
        int Real = (real * obj.real) - (imag * obj.imag);
        int Imag = (real * obj.imag) + (imag * obj.real);
        complex a(Real, Imag);
        return a;
    }

    int main()
    {
        complex a(1, 4), b(5, 1);
        complex c = a.multiply(b);
        c.display();
    }