/*
    ->Program for Insertion Sort
*/

#include<iostream>
using namespace std;

void insertionSort(int* arr,int size)
{
    for(int i = 1;i<size;i++)
    {
        for(int j = i - 1;j >= 0;j--)
        {
            int key = arr[j+1];
            if(key < arr[j] )
            {
                arr[j+1] = arr[j];
                arr[j] = key;
            }
        }
    }
}
int main()
{
    int size;
    cout << "\nEnter array size : ";
    cin >> size;
    int arr[size];
    cout << "\nEnter array : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    insertionSort(arr,size);
    cout << "\nSorted Array is : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}