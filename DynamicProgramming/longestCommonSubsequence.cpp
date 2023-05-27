/*
    Program : Printing Longest Common Subsequence
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "ABCBDAB";
    string s2 = "BDCABA";
    int size1 = s1.length();
    int size2 = s1.length();

    //Making table for longest common subsequence
    int t[size1+1][size2+1];
    for(int i = 0;i < size1+1;i++)
    {
        t[i][0] = 0;
    }
    for(int i = 0;i < size2+1;i++)
    {
        t[0][i] = 0;
    }

    for(int i = 1;i < size1+1;i++)
    {
        for(int j = 1;j<size2+1;j++)
        {
            if(s1[i-1] == s2[j-1] )
            {
                t[i][j] = 1 + t[i-1][j-1]; 
            }
            else if(t[i-1][j] >= t[i][j-1])
            {
                t[i][j] = t[i-1][j];
            }
            else
            {
                t[i][j] = t[i][j-1];
            }

        }
    }

    cout << "\nLength of Subsequence : " << t[size1][size2];
    
//---------------------------------------------------Printing the Longest Common Subsequence---------------------------------------------------------------
    //Using the table computed to traverse from bottom right corner till we reach top left corner(opposite of what we have done in table computation).
    string res = "";
    int i = size1,j = size2;                    //Starting from bottom right
    while(i != 0 && j != 0)                     //Loop in the table till we reach t[0][0]
    {
        if(t[i][j] == 1+t[i-1][j-1])            //Use condition of table if 2 character were equal we move diagonally and add 1 to the result.
        {
            res += s1[i-1];
            i = i - 1;
            j = j - 1;
        }
        else if(t[i-1][j] >= t[i][j-1])         //If 2 character we not equal we take maximum of either of 2 recursion call
        {                                       //Whichever value was maximum we move towards that direction either upward or to the left.
            i = i-1;
        }
        else
        {
            j = j - 1;
        }

    }
    reverse(res.begin(),res.end());             //Reverse the string as we have traversed table from bottom right to top left.
    cout << "\nSequence : " << res;
    return 0;
}