///workingg on itttt * not completed*


#include <iostream>
#include<list>
using namespace std;

class Graph
{
    int V;
    int **adj;

    public:
    Graph(int v)
    {
        this->V=v;

        int col,row;
        col=row=this->V;
        adj=new int*[row];
        for(int i=0;i<row;i++)
        {
            adj[i]=new int[col];
        }

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                adj[i][j]=0;
            }
        }
    }

    void addEdge(int s,int d)
    {
        if(s>=this->V)
        {
        cout<<"The source vertex value is not in range";
        return;
        }
        if(d>=this->V)
        {   
        cout<<"The destination vertex value is not in range";
        return;
        }
        adj[s].push_back(d);
        adj[d].push_back(s);
        adj[s].sort(); 
        adj[d].sort();
    }
};

void bfsOfGraph(int V, int adjList[MAX_V][MAX_V]) {
    int visited[MAX_V] = {0};
    int queue[MAX_V];
    int front = -1, rear = -1;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            enqueue(queue, rear, i);
            visited[i] = 1;

            while (front != rear) {
                int current = dequeue(queue, front);
                cout << current << " ";

                for (int j = 0; j < V; ++j) {
                    if (adjList[current][j] && !visited[j]) {
                        enqueue(queue, rear, j);
                        visited[j] = 1;
}
                }
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    int adjList[MAX_V][MAX_V] = {0};

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u][v] = 1;
    }

    cout << "BFS Traversal Order:\n";
    bfsOfGraph(V, adjList);

    return 0;
}

