/*
    Program : Kth Minimum ELement in the Array
*/
#include<bits/stdc++.h>
using namespace std;

//Function for partitioning array.
int partition(vector<int>& nums,int left,int right)
{
    int index = left-1;
    int pivot = right;
    for(int i = left;i<right;i++)
    {
        if(nums[pivot] > nums[i])
        {
            index++;
            swap(nums[index],nums[i]);
        }
    }
    swap(nums[index+1],nums[pivot]);
    return(index+1);
}

//Function to find kth minimum in an array
int kthMin(vector<int>& nums,int left,int right,int k)
{
    //If size of array is 1 or after partition only 1 element remains in the array
    if(left == right)
    {
        return nums[left];
    }
    //Calling function to find pivot index
    int part = partition(nums,left,right);
    //If partition index contains kth maximum element
    if(part == k-1)
    {
        return nums[part];
    }
    //else if kth maximum element is present on the right of the partition
    else if(part > k-1)
    {
        return kthMin(nums,left,part-1,k);
    }
    //else kth maximum element is present on the left of the partition
    else
    return kthMin(nums,part+1,right,k);
}

int main()
{
    cout << "\nEnter size of your array : ";
    int size;
    cin >> size;
    vector<int> nums(size);
    cout << "\nEnter element of the array : ";
    for(int i = 0;i<size;i++)
    {
        cin >> nums[i];
    }
    int k;
    cout << "\nEnter the value of k for finding kth minimum : ";
    cin >> k;
    cout << "\nAnswer : " << kthMin(nums,0,size-1,k);
    return 0;
}