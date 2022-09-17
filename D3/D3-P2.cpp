#include<iostream>

using namespace std;

class B;

class A
{
    int varA;
    public:
    A(int a):varA(a){};
    friend void func (A &objA, B &objB);
};

class B
{
    int varA;
    public:
    B(int a):varA(a){};
    friend void func (A &objA, B &objB);

};

void func (A &objA, B &objB)
{
    int sum = objA.varA + objB.varA;
    cout << sum << endl;
}


int main()
{
    A objA(3);
    B objB(5);
    func(objA, objB);
    return 0;
}