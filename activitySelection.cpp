/*
    Program : Activity Selection(Greedy)
*/

#include<bits/stdc++.h>
using namespace std;

//Comparator function to sort vector of pair accoring to its second element.
static bool fun(const pair<int,int>& p1,const pair<int,int>& p2)
{
    return (p1.second < p2.second);
}

int activitySelection(vector<int> start, vector<int> end, int n)
{
    // Your code here
    int count = 1;                                  //count is 1 because 1st activity is always done
    vector<pair<int,int>> startFinish;
    //Make a vector of pairs from 2 arrays where first element of pair stores starting time and second stores ending time
    for(int i = 0;i<n;i++)
    {
        startFinish.push_back(make_pair(start[i],end[i]));
    }
    //Sort the vector of pairs w.r.t second element i.e. according to finishing time in increasing order.
    sort(startFinish.begin(),startFinish.end(),fun);

    //Put the recently executed activity in curr
    int curr = 0;
    for(int i = 1;i<n;i++)
    {
        //If only one activity is performed in that hour or day we will not include those cases where finishing time of previous process
        //is equal to starting time of current process
        //If that is allowed we put equal sign otherwise not
        if(startFinish[i].first > startFinish[curr].second)
        {
            count++;
            curr = i;
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "\nEnter No. of Activities : ";
    cin >> n;
    vector<int> start(n), end(n);
    
    for(int i=0;i<n;i++)
    {
        cout << "\nEnter Starting Time : ";
        cin >> start[i];
        cout << "\nEnter Ending Time : ";
        cin >> end[i];
    }
    cout << "\nTotal Activities Performned : " << activitySelection(start, end, n);
    return 0;
}
