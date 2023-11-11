#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    
    public:
    Graph(int v);
    void addEdge(int src,int dest);
    void DFS(int root);
};

Graph::Graph(int v)
{
    this->V=v;
    adj=new list<int>[this->V];
}

void Graph::addEdge(int src,int dest)
{
    if(src>=this->V)
    {
        cout<<"The source vertex value is not in range";
        return;
    }
    if(dest>=this->V)
    {
        cout<<"The destination vertex value is not in range";
        return;
    }
    adj[src].push_back(dest);
    adj[src].sort();
    adj[src].reverse();
}

void Graph::DFS(int root)
{

    cout<<"DFS : ";

    vector<bool> visited(V,false);

    stack<int> st;

    st.push(root);
    
    list<int>::iterator i;
    while(!st.empty())
    {
        int s=st.top();
        st.pop();
        if(!visited[s])
        {
            cout<<s<<" ";
            visited[s]=true;
        }
        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                st.push(*i);
            }
        }
    }
}

int main()
{
    int v,src,dest,root,choice;
    cout<<"Enter the Number of vertex : ";
    cin>>v;
    if(v==0)
    {
        cout<<"Graph Doesn't Exist";
        return 0;
    }
    Graph A(v);
    while(1)
    {
        cout<<"\n\t1.Add Edge\n\t2.Depth First Search\n\t3.Exit\n";
        cout<<"\n\tEnter a Option: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nEnter Source Vertex :";
                cin>>src;
                cout<<"Enter Destination Vertex :";
                cin>>dest;
                A.addEdge(src,dest);
                break;
            case 2:
                cout<<"\nEnter the root node :";
                cin>>root;
                A.DFS(root);
                break;
            case 3:
                exit(0);
            default:
                cout<<"\nInvalid Option";
        }
    }
}
