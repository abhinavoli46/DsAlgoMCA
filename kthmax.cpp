#include<bits/stdc++.h>
using namespace std;

//Function for partitioning array.
int partition(vector<int>& nums,int start,int end)
{
    int index = start - 1;
    int pivot = end;

    for(int i = start;i<end;i++)
    {
        if(nums[pivot] < nums[i])
        {
            index++;
            swap(nums[i],nums[index]);
        }
    }
    swap(nums[index+1],nums[pivot]);
    return (index+1);
}

//Function to find kth maximum in an array
int kthMax(vector<int>& nums,int start,int end,int k)
{
    //If size of array is 1 or after partition only 1 element remains in the array
    if(start == end )
    {
        return nums[start];
    }
    //Calling function to find pivot index
    int part = partition(nums,start,end);
    //If partition index contains kth maximum element
    if(part == k-1)
    {
        return nums[part];
    }
    //else if kth maximum element is present on the right of the partition
    else if(part < k-1)
    {
        return kthMax(nums,part+1,end,k);
    }
    //else kth maximum element is present on the left of the partition
    else
        return kthMax(nums,start,part-1,k);

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
    cout << "\nEnter the value of k for finding kth maximum : ";
    cin >> k;
    cout << "\nAnswer : " << kthMax(nums,0,size-1,k);
    return 0;
}