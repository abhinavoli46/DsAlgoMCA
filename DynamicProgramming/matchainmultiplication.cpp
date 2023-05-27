#include<bits/stdc++.h>
using namespace std;
int s[10][10];
int fun(int arr[],int n)
{
    int t[n][n];

    //Base condition when i = j no multiplications are performed
    for(int i = 1;i<=n-1;i++)
    {
        t[i][i] = 0;
    }

    for(int l = 2;l<=n-1;l++)
    {
        for(int i = 1;i<(n-l+1);i++)
        {
            int j = i+l-1;

            t[i][j] = INT_MAX;
            for(int k = i; k < j;k++)
            {
                int q = t[i][k] + t[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(q < t[i][j])
                {
                    t[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return t[1][n-1];
}
void print(int i,int j)
{
    if(i == j)
    {
        cout << "A" << i+1;
        return;
    }
    else
    {
        cout << "(";
        print(i,s[i][j]);
        print(s[i][j]+1,j);
        cout << ")";
    }
}
int main()
{
    int arr [] = {4,10,3,12,20,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout << fun(arr,size);
    cout << endl;
    print(0,size-1);
    return 0;
}