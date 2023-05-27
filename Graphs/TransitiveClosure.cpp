#include<bits/stdc++.h>
using namespace std;

void transitiveClosure(vector<vector<int>>& adjMatrix)
{
    int size = adjMatrix.size();
    for(int k = 0;k<size;k++)
    {
        for(int i = 0;i < size;i++)
        {
            for(int j = 0;j < size;j++)
            {
                if(adjMatrix[i][k] != 0 && adjMatrix[k][j] != 0)
                {
                    adjMatrix[i][j] = adjMatrix[i][j] | (adjMatrix[i][k] & adjMatrix[k][j]);  
                }
            }
        }
    }
}

void printMatrix(vector<vector<int>> adjMatrix)
{
    for(int i = 0;i<adjMatrix.size();i++)
    {
        for(int j = 0;j<adjMatrix.size();j++)
        {
            cout << adjMatrix[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{
    int vertices,edges;
    cout << "\nEnter no of vertices : ";
    cin >> vertices;
    cout << "\nEnter no of edges : ";
    cin >> edges;
    //Make a matrix such that any vertex is not reachable from any vertex (denoted by 0).
    vector<vector<int>> adjMatrix(vertices,vector<int>(vertices,0));

    //Everey vertex is reachable from itself so make it 1
    for(int i = 0; i < vertices;i++)
    {
        adjMatrix[i][i] = 1;
    }
    //Mark 1 to other possible edges given in the graph
    for(int i = 0;i< edges;i++)
    {
        int source,destination;
        cout << "\nEnter source : ";
        cin >> source;

        cout << "\nEnter destination : ";
        cin >> destination;

        adjMatrix[source][destination] = 1;
    }
    cout << "\nOriginal Path Matrix : " << endl;
    printMatrix(adjMatrix);

    transitiveClosure(adjMatrix);

    cout << "\nFinal Paths Matrix(Transitive Closure) : " << endl;
    printMatrix(adjMatrix);

    return 0;
}