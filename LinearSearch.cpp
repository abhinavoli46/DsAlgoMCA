/*
    Program : Linear Search
*/
#include<bits/stdc++.h>
using namespace std;
int linearSearch(int* arr,int n,int key)
{
    for(int i = 0; i < n;i++)
    {
        if(arr[i] == key)
        {
            return i;
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
    cout << "\nEnter array : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "\nEnter the element to search : ";
    cin >> key;
    int res = linearSearch(arr,size,key);
    (res != -1) ? cout << "Found at " << res+1 << "position.": cout << "\nNot Found !";
    return 0;
}