/*
    Program : 0-1 Knapsack
*/

#include<bits/stdc++.h>
using namespace std;
int t[101][1001];
int knapsack(int Wt[],int cost[],int n,int capacity)
{
    //i represent current value of no of items availables
    //j represent maximum weight of bag to work on in the current moment
    for(int i = 1;i <n+1;i++)
    {
        for(int j = 1;j < capacity+1 ;j++)
        {
            //If current bag weight is greater than the weight of current ith element we are working on.
            if(j >= Wt[i-1])
            {
                t[i][j] = max(cost[i-1] +t[i-1][j-Wt[i-1]] ,t[i-1][j]);
            }
            //If current bag weight is less than the weight of current ith element we are working on. It means we cant insert that item in the bag.
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][capacity];
}
int main()
{
    //Initialize the matrix according to base condition
    for(int i = 0;i<101;i++)
    {
        for(int j = 0;j<1001;j++)
        {
            if(i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    int n,capacity;
    cout << "\nEnter the number of items : ";
    cin >> n;
    int Wt[n],val[n];
    for(int i = 0;i<n;i++)
    {
        cout << "\nEnter Weight of item " << i+1 << " : ";
        cin >> Wt[i];
        cout << "\nEnter Value of item " << i+1 << " : ";
        cin >> val[i];
    }
    cout << "\nEnter Capacity of Knapsack : ";
    cin >> capacity;
    
    cout << knapsack(Wt,val,n,capacity);
    return 0;
}