#include<iostream>
#include<cstdarg>
#include<cstring>
#include<exception>

using namespace std;

class tooHot : public exception
{
    int temp;
    string s;
    public:
    tooHot(int t) : temp(t){s = "\nTemperature " + to_string(temp) + " is too hot.\n";};
    ~tooHot(){};
    const char * what() const throw()
    {
        const char * S = s.data();
        return S;
    };
};

class tooCold : public exception
{
    int temp;
    string s;
    public:
    tooCold(int t) : temp(t){s = "\nTemperature " + to_string(temp) + " is too cold.\n";};
    ~tooCold(){};
    const char * what() const throw()
    {
        const char * S = s.c_str();
        return S;
    };
};

int main()
{
    int t;
    cout << "\nEnter the temperature: ";
    cin >> t;

    try
    {
        if(t > 40) {throw tooHot(t);;}
        else if(t < 20)   {throw tooCold(t);;}
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