#include<iostream>

using namespace std;

class A
{
	public:
	int varA, varB;
	A(int a, int b):varA(a), varB(b){cout << "\nclass A object initialized with: " << varA << ", " << varB << endl;};
};

void swap(A objA)
{
	int temp = objA.varA;
	objA.varA = objA.varB;
	objA.varB = temp;
}

void swap(A *objA)
{
	int temp = (objA)->varA;
	objA->varA = objA->varB;
	objA->varB = temp;
}

void swapref(A &objA)
{
	int temp = objA.varA;
	objA.varA = objA.varB;
	objA.varB = temp;
}

int main()
{
	A objA(3,5);
	swap(objA);
	cout << "\nAfter swap by value : " << objA.varA << ", " << objA.varB << endl;
	swap(&objA);
	cout << "\nAfter swap by pointer : " << objA.varA << ", " << objA.varB << endl;
	swapref(objA);
	cout << "\nAfter swap by reference : " << objA.varA << ", " << objA.varB << endl;
	return 0;
}