#include<bits/stdc++.h>
using namespace std;
int t[101][1001];
int knapsack(int Wt[],int cost[],int n,int W)
{
    //i represent current value of no of items availables
    //j represent maximum weight of bag to work on in the current moment 
    for(int i = 1;i < n+1;i++)
    {
        for(int j = 1;j < W+1;j++)
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

    return t[n][W];
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
    int Wt[] = {2,1,4,5,6};
    int val[] = {40,25,20,60,45};

    cout << knapsack(Wt,val,5,7);
    return 0;
}