/*
    Program : Count Sort
*/


#include<bits/stdc++.h>
using namespace std;
int maximum = INT_MIN,minimum = INT_MAX;
int takeInputAndReturnCountSize(int* arr,int size)
{
    for(int i = 0;i<size;i++)
    {
        cin >> arr[i];
        if(arr[i] >= maximum)
        {
            maximum = arr[i];
        }
         if(arr[i] <= minimum)
        {
            minimum = arr[i];
        }
    }
    return (maximum-minimum+1);
}
void printArray(int* arr,int size)
{
    for(int i = 0;i<size;i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    //Size of Input Array   
    int size;
    cin >> size;

    //Constructing Input Array
    int* arr = new int[size];

    //Constructing Result Array
    int* res = new int[size];

    //Taking imput and returning the range of count array
    int range = takeInputAndReturnCountSize(arr,size);

    //Creating count array and initializing to store frequencies.
    int* count = new int[range];
    for(int i = 0;i<range;i++)
    {
        count[i] = 0;
    }
    //Storing Frequencies of each element
    for(int i = 0;i<size;i++)
    {
        count[arr[i]-minimum]++;
    }
    //Storing cumulative frequencies in same count array
    for(int i = 1;i<range;i++)
    {
        count[i] += count[i-1];
    }
    
    //Traversing the complete input array from back and finding a suitable index for each element in res array using count array.
    for(int i = size-1;i>=0;i--)
    {
        res[count[arr[i]-minimum]-1] = arr[i];
        count[arr[i]-minimum]--;
    }
    cout << "\nArray after sorting : ";
    printArray(res,size);
    return 0;
}