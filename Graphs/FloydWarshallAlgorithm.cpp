#include<bits/stdc++.h>
using namespace std;
void floydWarshall(vector<vector<int>>& adjMatrix)
{
    int size = adjMatrix.size();
    cout << size;
    for(int k = 0;k < size;k++)
    {
        for(int i = 0;i < size;i++)
        {
            for(int j = 0;j < size;j++)
            {
                if(adjMatrix[i][k] < INT_MAX && adjMatrix[k][j] < INT_MAX)
                    adjMatrix[i][j] = min(adjMatrix[i][j],adjMatrix[i][k] + adjMatrix[k][j]);
            }
        }
    }
    //To check negative weight cycle
    for(int i = 0;i<size;i++)
    {
        if(adjMatrix[i][i] == 0)
        {
            continue;
        }
        else
        {
            cout << "\nThe graph have a negative weight cycle!";
            break;
        }
    }
}

void printMat(vector<vector<int>>& adjMatrix)
{
    int vertices = adjMatrix.size();
     for(int i = 0;i<vertices;i++)
    {
        for(int j = 0;j<vertices;j++)
        {
            cout << adjMatrix[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{
    int vertices;
    cout << "\nEnter the number of vertices : ";
    cin >> vertices;
    vector<vector<int>> adjMatrix(vertices,vector<int>(vertices));
    //Initialize the matrix
    for(int i = 0;i<vertices;i++)
    {
        for(int j = 0;j<vertices;j++)
        {
            if(i == j)
            {
                adjMatrix[i][j] = 0;
            }
            else
            {
                adjMatrix[i][j] = INT_MAX;
            }
            
        }
    }

    int edges;
    cout << "\nEnter the number of edges : ";
    cin >> edges;
    for(int i = 0;i<edges;i++)
    {
        int source,destination,weight;
        cout << "\nEnter source : ";
        cin >> source;
        cout << "\nEnter destination : ";
        cin >> destination;
        cout << "\nEnter weight : ";
        cin >> weight;
        adjMatrix[source][destination] = weight;
    }
    cout << endl;

    cout << "\nPassed Matrix : " << endl; 
    printMat(adjMatrix);

    floydWarshall(adjMatrix);

    cout << "\nResultant Matrix : " << endl;
    printMat(adjMatrix);
    return 0;
}