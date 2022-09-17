#include<iostream>
#include<cstring>
using namespace std;

class student
{
    string name, roll;
    int marks1, marks2, marks3;
    public:
    student();
    void display();
    friend void max(student arr[], int n);
};

student::student()
{
    string str1, str2;
    int a, b, c;
    cout << "Enter name: ";
    getline(cin, str1);
    cout << "Enter Roll: ";
    getline(cin, str2);
    cout << "Enter marks: ";
    cin >> a >> b >> c;
    cin.ignore();
    name = str1;
    roll = str2;
    marks1 = a;
    marks2 = b;
    marks3 = c;
}
void student::display()
{
    cout <<"\nName: "<<name<<"\nRoll: "<<roll<<"\nMarks 1: "<<marks1<<"\nMarks 2: "<<marks2<<"\nMarks 3: "<<marks3<<endl;
}

void max(student arr[], int n)
{
    int track = 0, max = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i].marks1 + arr[i].marks2 + arr[i].marks3;
        if (curr >= max)
        {
            max = curr;
            track = i;
        }
    }
    arr[track].display();
}

int main()
{
    student arr[3];
    max(arr, 3);
}
