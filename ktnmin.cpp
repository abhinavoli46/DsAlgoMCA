#include<bits/stdc++.h>
using namespace std;


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
void quickSort(vector<int>& nums,int left,int right)
{
    if(left < right)
    {
        int part = partition(nums,left,right);
        quickSort(nums,left,part-1);
        quickSort(nums,part+1,right);
    }
}
int kthMin(vector<int>& nums,int left,int right,int k)
{
    if(left == right)
    {
        return nums[left];
    }
    int part = partition(nums,left,right);
    
    if(part == k-1)
    {
        return nums[part];
    }
    else if(part > k-1)
    {
        return kthMin(nums,left,part-1,k);
    }
    else
    return kthMin(nums,part+1,right,k);
}
int main()
{
    vector<int> nums = {3,2,3,1,4,5,5,4};
    cout << "\nBefore : ";
    for(auto x : nums)
    {
        cout << x << " ";
    }
    int left = 0,right = nums.size()-1;
    cout << endl;
    cout << kthMin(nums,left,right,4);
    
    cout << "\nAfter : ";
    for(auto x : nums)
    {
        cout << x << " ";
    }
    return 0;
}