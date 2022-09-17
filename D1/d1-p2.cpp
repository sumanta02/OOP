#include<iostream>

using namespace std;

int binarySearch (int arr[], int lo, int hi, int num);
void insertionSort (int arr[], int n);
void display (int arr[], int n);

int main()
{
    int arr[10];
    int num;
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }
    display(arr, 10);
    cout << "\nEnter a number to search in the array: ";
    cin >> num;
    int pos = binarySearch(arr, 0, 9, num);
    if (pos != -1) cout << "\nThe " << num << "is found at position: " << pos << "\n";
    else cout << "\nThe num (" << num << ") is not found in the array.\n";
    insertionSort(arr, 10);
    return 0;
}

int binarySearch (int arr[], int lo, int hi, int num)
{
    if (hi >= lo){
        int mid = (lo +  hi) / 2;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] > num)
            return binarySearch (arr, lo, mid - 1, num);    
        return binarySearch (arr, mid + 1, hi, num);
    }
    return -1;
}
void insertionSort (int arr[], int n)
{
    int i, key, j; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    }
    display(arr, n);
}
void display (int arr[], int n)
{
    cout << "\nArray: \n";
    for (int i = 0; i < n; i++) {cout << arr[i] << "\n";}
}