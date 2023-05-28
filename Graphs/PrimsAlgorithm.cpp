/*
    Program : Prims Algorithm
*/

#include<bits/stdc++.h>
using namespace std;

void primsAlgo(vector<pair<int,int>> adj[],int V,int& minCost)
{
    //Make min heap of pair of a integer representing cost and pair representing source and destination.  Node in a heap will be {cost,{parent,neighbour}}
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    //Array for marking visited node
    vector<bool> visited(V,false);
    //Array to store mst
    vector<pair<int,int>> mst;
    //Our queue will take values as {cost,{source,destination}}
    
    //Put any node in the queue here we have put 0, cost to reach 0 is 0 and its parent is -1(not defined)
    pq.push({0,{-1,0}});
    
    while(!pq.empty())
    {
        int distance = pq.top().first;
        int parentNode = pq.top().second.first;
        int currNode = pq.top().second.second;
        pq.pop();
        //If A node is already visited do not make any changes
        if(visited[currNode] == 1) continue;
        //If parent node is other than initial node parent
        if(parentNode != -1)
        {
            mst.push_back({parentNode,currNode});
        }
        visited[currNode] = 1;
        minCost += distance;

        //Put neighbours of current node into the heap only if they are not visited
        for(auto x : adj[currNode])
        {
            //See line in main where values are pushed for a particular node only destination and cost were stored in a pair and added.
            int neighbour = x.first;
            int cost = x.second;

            if(visited[neighbour] == 0)
            {
                pq.push({cost,{currNode,neighbour}});
            }
        }

    }
    cout << "\n MST is : ";
    for(auto x : mst)
    {
        cout << x.first << " " << x.second << " ";
    }

}
int main()
{
    int minCost = 0;
    int n_vertices,n_edges;
    cout << "\nEnter the number of vertices : ";
    cin >> n_vertices;
    cout << "\nEnter the number of edges : ";
    cin >> n_edges;

    /* Make a 2d vector of pair type where pair stores {adjacentNode,cost}
     1 -> {{3,6},{4,3}}
     2 -> {{1,3}}
     3 -> {{4,2}}
     4 -> {{2,1},{4,2}}
    */
    vector<pair<int,int>> adjList[n_vertices];
    //Fill the adjacency matrix for every edge (not vertex), every edge has 2 vertices and common cost
    for(int i = 0;i<n_edges;i++)
    {
        int source,destination,cost;
        cout << "\nEnter source : ";
        cin >> source;
        cout << "\nEnter destination : ";
        cin >> destination;
        cout << "\nEnter cost : ";
        cin >> cost;
        adjList[source].push_back(make_pair(destination,cost));
        adjList[destination].push_back(make_pair(source,cost));  
    }
    primsAlgo(adjList,n_vertices,minCost);
    cout << "\nMinimum Cost : " << minCost;
    return 0;
}