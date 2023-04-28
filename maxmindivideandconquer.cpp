/*
    Program : Minimum and Maximum inside an array using divide and conquer
*/
#include<bits/stdc++.h>
using namespace std;

void findMinMax(vector<int>& nums,int start,int end,pair<int,int>& res)
{
    //Base Condition 1 : When array size is 1/After dividing array size reaches to 1.
    if(start == end)
    {
        res.first = min(res.first,nums[start]);
        res.second = max(res.second,nums[end]);
        return;
    }
    //Base Condition 2 : When array size is 2/After dividing array size reaches to 2.
    if(end - start == 1)
    {
        res.first = min(res.first,min(nums[start],nums[end]));
        res.second = max(res.second,max(nums[start],nums[end]));
        return;
    }
    //Break array into two parts with the help of mid index and call function for left and right part.
    int mid = start + (end-start)/2;
    findMinMax(nums,start,mid,res);
    findMinMax(nums,mid+1,end,res);
}

int main()
{
    int size = 0;
    pair<int,int> res;
    //VALUE INSIDE PAIR ARE ASSIGNED TO 0 BY DEFAULT, SO WE NEED TO MAKE THEM HIGHEST POSSIBLE FOR MINIMUM VARIABLE AND 
    //LOWEST POSSIBLE FOR MAXIMUM VARIABLE
    //first value of pair stores the minimum element of the array.
    //second value of pair stores the maximum element of the array.

    res.first = INT_MAX;
    res.second = INT_MIN;
    //Enter Array Size
    cout << "\nEnter the size of Array : ";
    cin >> size;
    //Enter values inside array
    cout << "\nEnter your Array : ";

    vector<int> nums(size);
    for(int i = 0;i<size;i++)
    {
        cin >> nums[i];
    }

    //Function to modify pair such that its first element contains minimum element of the array and its 
    //second element contain maximum element of array.
    findMinMax(nums,0,size-1,res);

    cout << "\nMinimum Element : " << res.first;
    cout << "\nMaximum Element : "  << res.second;
    return 0;
}