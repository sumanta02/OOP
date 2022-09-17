#include<iostream>

using namespace std;

class Base
{
    public:
    Base()
    {
        cout<< "Base constructor call"<<endl;
    }

    virtual void func1()
    {
        cout<<"func 1 of Base"<<endl;
    }

    void func2()
    {
        cout<<"func 2 of Base (early binding happening here)"<<endl;
    }

    virtual ~Base()
    {
        cout<< "Base destructor call"<<endl;
    }
};

class Derived:public Base
{
    public:
    Derived()
    {
        cout<< "Derived constructor call"<<endl;
    }

    virtual void func1()
    {
        cout<<"func 1 of Derived (late binding happening here)"<<endl;
    }

    void func2()
    {
        cout<<"func 2 of Derived (early binding happening here)"<<endl;
    }

    ~Derived()
    {
        cout<< "Derived destructor call"<<endl;
    }
};

int main()
{
    Base b;
    b.func2();
    Derived d1;
    Base *bptr=&d1;
    bptr->func1();
    Derived d2;
    d2.func2();
    return 0;
}
