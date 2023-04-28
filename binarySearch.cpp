/*
    Program : Binary Search
*/

#include<bits/stdc++.h>
using namespace std;
int binarySearch(int* arr,int start,int end,int key)
{
    while(start < end)
    {
        int mid = (start + (end-start)/2);
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(key >arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

    }
    return -1;
}
int main()
{
    int size,key;
    cout << "\nEnter array size : ";
    cin >> size;
    int arr[size];
    cout << "\nEnter array in sorted form: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "\nEnter the element to search : ";
    cin >> key;
    int res = binarySearch(arr,0,size,key);
    (res != -1) ? cout << "Found at " << res+1 << " position.": cout << "\nNot Found !";
    return 0;
}