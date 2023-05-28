#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adjList[],int vertices,int source)
{
    vector<bool> visited(vertices,false);
    stack<int> container;
    container.push(source);
    visited[source] = true;
    while(!container.empty())
    {
        int top = container.top();
        visited[top] = true;
        container.pop();
        cout << top << " ";
        
        for(auto x : adjList[top])
        {
            if(visited[x] != true)
            {
                container.push(x);
                visited[x] = true;
            }
        }
    }
    

}
int main()
{
    int vertices,edges;
    cout << "\nEnter the number of vertices : ";
    cin >> vertices;
    cout << "\nEnter the number of edges : ";
    cin >> edges;
    vector<int> adjList[vertices];

    for(int i = 0;i<edges;i++)
    {
        int source,destination;
        cout << "\nEnter source : ";
        cin >> source;
        cout << "\nEnter destination : ";
        cin >> destination;
        adjList[source].push_back(destination);
        // adjList[destination].push_back(source);
    }
    int source;
    cout << "\nEnter a source to start : ";
    cin >> source;

    cout << "\nThe path for dfs is : ";
    dfs(adjList,vertices,source);
    return 0;
}