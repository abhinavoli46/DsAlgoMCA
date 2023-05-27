#include<bits/stdc++.h>
using namespace std;

bool BellmanFord(vector<pair<pair<int,int>,int>> adjList,int vertices,int source)
{
    vector<int> distance(vertices,1e8);
    vector<int> predecessor(vertices,0);
    distance[source] = 0;

    for(int i = 0;i<vertices-1;i++)
    {
        for(auto x : adjList)
        {
            int u = x.first.first;
            int v = x.first.second;
            int w = x.second;
            if(distance[u] != 1e8 && distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                predecessor[v] = u;
            }

        }
    }

    for(auto x : adjList)
    {
        int u = x.first.first;
        int v = x.first.second;
        int w = x.second;
        if(distance[u] != 1e8 && distance[u] + w < distance[v])
        {
            return false;
        }
    }
    cout << "\nDistance Array : ";
    for(auto x : distance)
    {
        cout << x << " ";
    }
    cout << "\nPredecessor Array : ";
    for(auto x : predecessor)
    {
        cout << x << " ";
    }
    return true;
}
int main()
{
    int vertices,edges;
    cout << "\nEnter vertices : ";
    cin >> vertices;
    cout << "\nEnter edges : ";
    cin >> edges;
    vector<pair<pair<int,int>,int>> adjList;

    for(int i = 0;i<edges;i++)
    {
        int source,destination,weight;
        cout << "\nEnter source : ";
        cin >> source;
        cout << "\nEnter destination : ";
        cin >> destination;
        cout << "\nEnter weight : ";
        cin >> weight;

        adjList.push_back(make_pair(make_pair(source,destination),weight));
       
        
    }
     int start;
    cout << "\nEnter a source : ";
        cin >> start;

        BellmanFord(adjList,vertices,start);
    return 0;
}