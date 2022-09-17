#include<iostream>

using namespace std;

class Student
{
    int Roll;
    public:
    Student(int roll = 0):Roll(roll){cout << "\nStudent Class initialized with: Roll: " << roll << endl;};
    void getRoll()
    {cout << "\nRoll : " << Roll << endl;};
    ~Student(){cout << "\nStudent class destroyed.\n";};
};

class test: virtual public Student
{
    protected:
    int marks1, marks2;
    public:
    test(int a = 0, int b = 0):marks1(a), marks2(b){cout << "\nTest class initialized with: Mark 1: " << marks1 << ", Mark 2: " << marks2 << endl; };
    void getMarks()
    {
        cout << "\nMarks 1: " << marks1 << ", Marks2: " << marks2 << endl;
    };
    ~test(){cout << "\nTest class destroyed.\n";};
};

class Sports: virtual public Student
{
    protected:
    int Score;
    public:
    Sports(int a = 0): Score(a){cout << "\nSports Class initialized with: Score: " << Score << endl;};
    void getScore()
    {
        cout << "\nEnter the Sports Score: ";
        cin >> Score;
    };
    void putScore(){cout << "\nSports Score: " << Score << endl;};
    ~Sports(){cout << "\nSports class destroyed.\n";};
};

class result: public test, public Sports
{
    protected:
    int total;
    public:
    result(int roll, int mark1, int mark2, int score = 0):Student(roll), test(mark1, mark2){total = 0; cout << "\nResult class initialized with: Total: " << total << endl;};
    void getTotal(){total = marks1 + marks2 + Score;cout << "\nTotal marks: " << total << endl;};
    ~result(){cout << "\nResult class destroyed.\n";};
};

int main()
{
    int roll, mark1, mark2, score;
    cout << "\nEnter the roll, marks of both subjects and of the student: ";
    cin >> roll >> mark1 >> mark2;
    result s(roll, mark1, mark2, score);
    s.getRoll();
    s.getMarks();
    s.getScore();

    s.putScore();
    s.getTotal();
}