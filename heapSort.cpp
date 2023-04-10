#include<bits/stdc++.h>
using namespace std;
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int* arr,int size,int index)
{
    int largest = index;
    int l = (2*index) + 1;
    int r = (2*index) + 2;
    
    if(l < size && arr[l] > arr[largest])
    {
        largest = l;
    }
    
    if(r < size && arr[r] > arr[largest])
    {
        largest = r;
    }
    if(largest != index)
    {
        swap(arr[largest],arr[index]);
        heapify(arr,size,largest);
    }
}

void makeHeap(int* arr,int size)
{
    for(int i = floor(size/2)-1;i >= 0;i--)
    {
        heapify(arr,size,i);
    }
}

void heapSort(int* arr,int size)
{
    makeHeap(arr,size);
    for(int i = size-1;i >= 1;i--)
    {
        
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
void printArray(int* arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int size;
    cout << "Enter size of array : ";
    cin >> size;
    int* arr = new int[size];
    cout << " \nEnter Array : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << " \nArray Before Sorting : ";
    printArray(arr,size);

    heapSort(arr,size);
     
    cout << " \nArray After Sorting : "; 
    printArray(arr,size);
    
    delete[] arr;  
    return 0;
}