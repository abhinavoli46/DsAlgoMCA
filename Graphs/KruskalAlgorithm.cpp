/*
    Program : Kruskal Algorithm
*/

#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
void kruskal(vector<vector<int>> adj[],int V,int& minCost)
{
    vector<pair<int,pair<int,int>>> edges;
    vector<pair<int,int>> mst;
    for(int i = 0;i<V;i++)
    {
        for(auto x : adj[i])
        {
            int neighbour = x[0];
            int cost = x[1];
            int currNode = i;

            edges.push_back({cost,{currNode,neighbour}});
        }
    }
    DisjointSet ds(V);
    //Sort Edges according to cost
    sort(edges.begin(),edges.end());

    for(auto x:edges)
    {
        int cost = x.first;
        int source = x.second.first;
        int destination = x.second.second;
        //Check if both the vertices belong to same copmponent or both have same root node, if they are different then add cost and do union
        if(ds.findUPar(source) != ds.findUPar(destination))
        {
            minCost += cost;
            mst.push_back({source,destination});
            ds.unionBySize(source,destination);
        }
    }
    cout << "\nMinimum Spanning Tree : ";
    for(auto x : mst)
    {
        cout << x.first <<" " << x.second << " ";
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

    /*Make an array of array of vector where outer vector is of source vertices and inner vector is of destination and cost between source and destination.
     1 -> {{3,6},{4,3}}
     2 -> {{1,3}}
     3 -> {{4,2}}
     4 -> {{2,1},{4,2}}
    */
    vector<vector<int>> adjList[n_vertices];
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

        vector<int> t1;
        vector<int> t2;

        t1.push_back(destination);
        t1.push_back(cost);
        adjList[source].push_back(t1);

        t2.push_back(source);
        t2.push_back(cost);
        adjList[destination].push_back(t2);

        
    }
    kruskal(adjList,n_vertices,minCost);
    cout << "\nMinimum Cost : " << minCost;
}