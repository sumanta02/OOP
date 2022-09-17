#include<iostream>
#include<cmath>

using namespace std;

class shape
{
    protected:
    int l, w, h, r;
    public:
    shape(int a, int b, int c):l(a), w(b), h(c){};
    shape(int rad, int hi):r(rad), h(hi){};
    virtual void calc() = 0;
    virtual ~shape()
    {
        cout << "\nShape Destuctor Call\n";
    };
};

class cuboid : public shape
{
    public:
    cuboid(int a, int b, int c):shape(a,b,c){};
    void calc()
    {
        cout << "\nCuboid surface area: " << 2 * (l * w + w * h + h * l) << endl;
        cout << "\nCuboid volume: " << (l * w * h) << endl;
        return;
    };
    virtual ~cuboid()
    {
        cout << "\nCuboid Destuctor Call\n";
    };
};

class cone : public shape
{
    public:
    cone(int rad, int hi):shape(rad, hi){};
    void calc()
    {
        cout << "\nCone surface area: " << M_PI * r * (r + sqrt(h * h + r * r)) << endl;
        cout << "\nCone volume: " << 0.33 * h * M_PI * r * r << endl;
        return;
    };
    virtual ~cone()
    {
        cout << "\nCone Destuctor Call\n";
    };
};

class cylinder : public shape
{
    public:
    cylinder(int rad, int hi): shape(rad, hi){};
    void calc()
    {
        cout << "\nCylinder surface area: " << 2*M_PI*r*(r+h) << endl;
        cout << "\nCylinder volume: " << M_PI * r * r * h << endl;
        return;
    };
    virtual ~cylinder()
    {
        cout << "\nCylinder Destuctor Call\n";
    };
};

int main()
{
    int l,w,h,r;
    shape *s;
    cout << "\nEnter dimensions of cuboid(l,w,h):\n";
    cin >> l >> w >> h;
    cuboid a(l,w,h);
    s=&a;
    s->calc();
    cout << "Enter dimensions of cone(r,h):\n";
    cin >> r >> h;
    cone b(r,h);
    s=&b;
    s->calc();
    cout << "Enter dimensions of cylinder(r,h):\n";
    cin >> r >> h;
    cylinder c(r,h);
    s=&c;
    s->calc();
    return 0;
}