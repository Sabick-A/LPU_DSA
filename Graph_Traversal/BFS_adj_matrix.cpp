#include<iostream>
#include<list>

using namespace std;

void BFS(int root,int V,int adj[100][100])
{
    int visited[V]={0};
    list<int>q;
    q.push_back(root);
    visited[root]=1;
    while(!q.empty())
    {
        int s=q.front();
        cout<<s<<" ";
        q.pop_front();
        for(int j=0;j<V;j++)
        {
            if(adj[s][j]==1 && visited[j]!=1)
            {
                q.push_back(j);
                visited[j]=1;
            }
        }
    }
}
int main()
{
    int V,E,u,w,root;
    cin>>V>>E;
    int adj[100][100]={0};
    for(int i=0;i<E;i++)
    {
        cin>>u>>w;
        adj[u][w]=1;
    }
    
    cout<<"\nBFS traversal graph";
    BFS(0,V,adj);
    return 0;
}