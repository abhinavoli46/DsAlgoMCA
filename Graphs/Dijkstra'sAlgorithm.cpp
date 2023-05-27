#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<pair<int,int>> adjList[], int vertices, int source)
{
    // INITIALIZE_SINGLE_SOURCE
    vector<int> distance(vertices,INT_MAX);
    vector<int> predecessor(vertices,-1);
    vector<int> visited(vertices, false);
    distance[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Push source with cost 0
    pq.push({0, source}); //{weight,node}
    while (!pq.empty())
    {
        int currNode = pq.top().second; // u
        // As one edge can be relaxed only one time so we make the popped node as visited
        visited[currNode] = true;
        pq.pop();

        for (auto x : adjList[currNode])
        {
            // Each neighbouring node is stored as {neighbour,cost_to_reach_neighbour from current node}

            int adjNode = x.first;    // v
            int edgeWeight = x.second; // w(u,v)

            if (visited[adjNode] == true)
                continue; // If a node is already visited we continue (this is where dijkstra fails as
                          // if negative weight is present in further path it will decrese the distance
                          // but we will not consider it as we marked the node as visited)
            // RELAXATION
            if (distance[adjNode] > distance[currNode] + edgeWeight)
            {
                distance[adjNode] = distance[currNode] + edgeWeight;
                predecessor[adjNode] = currNode;
                pq.push({distance[adjNode], adjNode});
            }
        }
    }

    cout << "\nMinimum Distance Array: ";
    for (int i = 0; i < vertices; i++)
    {
        cout << distance[i] << " ";
    }

    cout << "\nPredecessor Array : ";

    for (int i = 0; i < vertices; i++)
    {
        cout << predecessor[i] << " ";
    }
}
int main()
{
    int edges, vertices;
    cout << "\nEnter the number of vertices : ";
    cin >> vertices;
    cout << "\nEnter the number of edges : ";
    cin >> edges;

    vector<pair<int,int>> adjList[vertices];

    for (int i = 0; i < edges; i++)
    {
        int source, destination, weight;
        cout << "\nEnter source : ";
        cin >> source;
        cout << "\nEnter destination : ";
        cin >> destination;
        cout << "\nEnter weight : ";
        cin >> weight;

        adjList[source].push_back(make_pair(destination,weight));
    }

    int source;
    cout << "\nEnter the source from where you want to search the shotest path to all the nodes : ";
    cin >> source;
    dijkstra(adjList, vertices, source);
    return 0;
}