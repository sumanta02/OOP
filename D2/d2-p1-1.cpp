#include<iostream>

using namespace std;

class Time 
{
    int hour, minute, second;
    public:
    Time (int a = 0, int b = 0, int c = 0):hour(a), minute(b), second(c){};
    Time add(Time);
    inline void display ()
    {
            cout <<hour<<" hour "<<minute<<" minutes "<<second<<" seconds.\n";
    };
};

Time Time::add(Time obj)
{
    int hours = 0, minutes = 0, seconds = (second + obj.second) % 60;
    if ((second + obj.second) >= 60 ) minutes++;
    minutes += minute + obj.minute;
    if (minutes >= 60 ) hours++;
    minutes %= 60;
    hours += hour + obj.hour;
    Time obj2(hours, minutes, seconds);
    return obj2;
}

int main()
{
    Time a(0,59,59), b(0,59,59);
    Time c;
    c = a.add(b);
    a.display();
    b.display();
    c.display();
    return 0;
}