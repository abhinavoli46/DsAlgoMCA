#include<bits/stdc++.h>
using namespace std;

void countSort(int* arr,int size,int place)
{
    //Constructing Result Array
    int* res = new int[size];
    int* count = new int[10];
    for(int i = 0;i<10;i++)
    {
        count[i] = 0;
    }

    //Storing Frequencies of each element
    for(int i = 0;i<size;i++)
    {
        count[((arr[i])/place) % 10]++;
    }

    //Storing cumulative frequencies in same count array
    for(int i = 1;i<10;i++)
    {
        count[i] += count[i-1];
    }
    
    //Traversing the complete input array from back and finding a suitable index for each element in res array using count array.
    for(int i = size-1;i>=0;i--)
    {
        res[count[((arr[i])/place)%10]-1] = arr[i];
        count[((arr[i])/place)%10]--;
    }
    //Copy the resulted array to original array each time array is sorted accoring to different radix.
    for(int i = 0;i<size;i++)
    {
        arr[i] = res[i];
    }
}


int main()
{  
    //Constructing Input Array
    int size;
    cout << "\nEnter the size of array : ";
    cin >> size;
    cout << "\nEnter array elements : ";
    int* arr = new int[size];
    for(int i = 0;i<size;i++)
    {
        cin >> arr[i];
    }
    //Find Maximum Element in the array
    int maxi = INT_MIN;
    for(int i = 0;i < size;i++)
    {
        maxi = max(maxi,arr[i]);
    }

    //Loop will terminate when largest number in the array become 0 or all the places are visited.
    for(int place = 1;maxi/place > 0;place*=10)
    {
        countSort(arr,size,place);
    }

    cout << "\nArray in sorted form : ";
    for(int i =0 ;i< size;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;

}