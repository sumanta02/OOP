#include<iostream>
#include<cstdarg>
#include<cstring>
#include<exception>

using namespace std;

class tooHot : public exception
{
    int temp;
    public:
    tooHot(int t) : temp(t){};
    ~tooHot() throw() {};
    const char * what() const throw()
    {
        cout << "\nTemperature: " << temp;
        return " is too hot.\n";
    };
};

class tooCold : public exception
{
    int temp;
    public:
    tooCold(int t) : temp(t){};
    ~tooCold() throw() {};
    const char * what() const throw()
    {
        cout << "\nTemperature: " << temp;
        return " is too cold.\n";
    };
};

int main()
{
    int t;
    cout << "\nEnter the temperature: ";
    cin >> t;

    try
    {
        if(t > 40) {throw tooHot(t);}
        else if(t < 20)   {throw tooCold(t);}
        cout << "\nTemperature: " << t << endl;
    }

    catch(tooHot & obj)
    {
        cout << obj.what();
    }
    
    catch(tooCold & obj)
    {
        cout << obj.what();
    }

    return 0;
}