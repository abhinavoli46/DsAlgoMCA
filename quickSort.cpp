#include<bits/stdc++.h>
using namespace std;
int lpartition(int* arr,int l,int h)
{
    int index = l - 1;
    int pivot = h;
    for(int i = l;i < h;i++)
    {
        if(arr[i] < arr[pivot])
        {
            index++;
            swap(arr[i],arr[index]);
        }
    }
    swap(arr[index+1],arr[pivot]);
    return (index+1);
}
void quickSort(int* arr,int start,int end)
{
    if(start < end)
    {
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