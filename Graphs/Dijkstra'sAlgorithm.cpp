#include<bits/stdc++.h>
using namespace std;

void initialization(vector<int>& distance,vector<int>& predecessor,int vertices,int source)
{
    for(int i = 0;i < vertices;i++)
    {
        distance[i] = INT_MAX;
        predecessor[i] = -1;
    }
    distance[source] = 0;

}

void dijkstra(vector<vector<int>> adjList[],int vertices,int source)
{
    //INITIALIZE_SINGLE_SOURCE
    vector<int> distance(vertices);
    vector<int> predecessor(vertices);
    vector<int> visited(vertices,false);
    initialization(distance,predecessor,vertices,source);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    //Push source with cost 0
    pq.push({0,source});   //{weight,node}
    while(!pq.empty())
    {
        int currNode = pq.top().second; //u
        //As one edge can be relaxed only one time so we make the popped node as visited
        visited[currNode] = true;
        pq.pop();

        for(auto x : adjList[currNode])
        {
            //Each neighbouring node is stored as {neighbour,cost_to_reach_neighbour from current node}
            
            int adjNode = x[0];             //v
            int edgeWeight = x[1];          //w(u,v)

            if(visited[adjNode] == true) continue;              //If a node is already visited we continue (this is where dijkstra fails as if negative weight is present in further path it will decrese the distance but we will not consider it as we marked the node as visited)
            //RELAXATION
            if(distance[adjNode] > distance[currNode] + edgeWeight)
            {
                distance[adjNode] = distance[currNode] + edgeWeight;
                predecessor[adjNode] = currNode;
                pq.push({distance[adjNode],adjNode});
            }
        }
    }

    cout << "\nMinimum Distance Array: ";
    for(int i = 0;i<vertices;i++)
    {
        cout << distance[i] << " ";
    }

    cout << "\nPredecessor Array : ";

    for(int i = 0;i<vertices;i++)
    {
        cout << predecessor[i] << " ";
    }

}
int main()
{
    int edges,vertices;
    cout << "\nEnter the number of vertices : ";
    cin >> vertices;
    cout << "\nEnter the number of edges : ";
    cin >> edges;

    vector<vector<int>> adjList[vertices];

    for(int i = 0;i<edges;i++)
    {
        int source,destination,weight;
        cout << "\nEnter source : ";
        cin >> source;
        cout << "\nEnter destination : ";
        cin >> destination;
        cout << "\nEnter weight : ";
        cin >> weight;
        
        vector<int> t;
        t.push_back(destination);
        t.push_back(weight);
        adjList[source].push_back(t);
        
    }
    
    int source;
    cout << "\nEnter the source from where you want to search the shotest path to all the nodes : ";
    cin >> source;
    dijkstra(adjList,vertices,source);
    return 0;
}