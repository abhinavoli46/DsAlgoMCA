/*
    Program : Quick Sort
*/
#include<bits/stdc++.h>
using namespace std;
int lpartition(int* arr,int l,int h)
{
    //Initialize an index which is less than low index i.e. -1
    int index = l - 1;
    //Pivot is the last element in this case
    int pivot = h;
    for(int i = l;i < h;i++)
    {
        //When an element on left side of pivot is less than pivot 
        if(arr[i] < arr[pivot])
        {
            //Increase index and swap value at index with value at ith index which is less than pivot.
            index++;
            swap(arr[i],arr[index]);
        }
    }
    //At last put pivot element at correct position and return position of pivot element.
    swap(arr[index+1],arr[pivot]);
    return (index+1);
}
void quickSort(int* arr,int start,int end)
{
    if(start < end)
    {
        //First find position of pivot element then apply quick sort on both side of pivot
        int pivot = lpartition(arr,start,end);
        quickSort(arr,start,pivot-1);
        quickSort(arr,pivot+1,end);
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
    quickSort(arr,0,size-1);
    cout << "\nSorted Array is : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}