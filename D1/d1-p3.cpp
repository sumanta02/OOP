#include<iostream>

using namespace std;

struct Time 
{
    int hour, minute, second;
};

void display (Time obj)
{
    cout <<obj.hour<<" hour "<<obj.minute<<" minutes "<<obj.second<<" seconds.\n";
};

Time add(Time obj1, Time obj2)
{
    int hours = 0, minutes = 0, seconds = (obj1.second + obj2.second) % 60;
    if ((obj1.second + obj2.second) >= 60 ) minutes++;
    minutes += obj1.minute + obj2.minute;
    if (minutes >= 60 ) hours++;
    minutes %= 60;
    hours += obj2.hour + obj2.hour;
    Time obj3;
    obj3.hour = hours;
    obj3.minute = minutes;
    obj3.second = seconds;
    return obj3;
}

int main()
{
    Time a, b, c;
    a.hour = 0;
    a.minute = 59;
    a.second = 59;
    b.hour = 0;
    b.minute = 59;
    b.second = 59;
    c = add(a, b);
    display(a);
    display(b);
    display(c);
    return 0;
}