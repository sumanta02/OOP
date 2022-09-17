#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(double);
bool isFib(double);

int func(double);

int main()
{
    double num;
    cout << "\nEnter a number: ";
    cin >> num;
    if (func(num))  cout << "\nThe number is both prime and fibonacci.\n";
    else cout << "\nThe number is not both prime and fibonacci.\n";
    return 0;
}

bool isPrime(double num)
{
    for (int i = 2; i <= (int)sqrt(num); i++)
    {
        if (!((int)num % i)) return false;
    }
    return true;
}
bool isFib(double num)
{
    int first = 0, second = 1, result = 0;
    while (result <= num)
    {
        first = second;
        second = result;
        result = first + second;
    }
    if (second == num) return true;
    return false;
}
int func(double num)
{
    if (isPrime(num) && isFib(num)) return true;
    return false;
}