
#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) 
{
    bool visited[V+1];
    vector<int> res;
    for(int i = 0;i<V;i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    q.push(0);
    visited[0] = true;
    
    while(!q.empty())
    {
        int value = q.front();
        q.pop();
        
        res.push_back(value);
        
        for(auto x : adj[value])
        {
            if(visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }   
    return res;
}


int main() 
{
    //Adjacency List Representation
    
    int vertices, edges;
    cout << "\nEnter no. of vertices and edges : ";
    cin >> vertices >> edges;

    //Make a vector of array of adjacent vertices
    vector<int> adj[vertices];
    for (int i = 0; i < edges; i++) 
    {
        int end1, end2;
        cin >> end1 >> end2;
        adj[end1].push_back(end2);
    }
       
    vector<int> ans = bfsOfGraph(vertices, adj);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
