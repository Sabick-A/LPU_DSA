#include<bits/stdc++.h>

using namespace std;

class Graph 
{
    int V;
    list<int> *adj;
    
    public:
    Graph(int v)
    {
        this->V=v;
        adj=new list<int>[this->V];
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

    void BFS(int root)
    {
        cout<<"Bread First Search: ";
        vector<bool> visited(this->V,false);
        visited[root]=true;

        list<int> q;
        q.push_back(root);
        while(!q.empty())
        {
            int s=q.front();
            q.pop_front();
            cout<<s<<" -> ";

            list<int> ::iterator i;

            for(i=adj[s].begin();i!=adj[s].end();i++)
            {
                if(!visited[*i])
                {
                    visited[*i]=true;
                    q.push_back(*i);
                }
            }
        }
    }

};

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
        cout<<"\n\t1.Add Edge\n\t2.Add N number of edges\n\t3.Breadth First Search\n\t4.Exit\n";
        cout<<"\n\tEnter a Option: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nEnter Source Vertex :";
                cin>>src;
                cout<<"\nEnter Destination Vertex :";
                cin>>dest;
                A.addEdge(src,dest);
                break;
            case 2:
                int n;
                cout<<"\nEnter N :";
                cin>>n;
                for(int i=0;i<n;i++)
                {
                cout<<"\nEnter Source Vertex :";
                cin>>src;
                cout<<"\nEnter Destination Vertex :";
                cin>>dest;
                A.addEdge(src,dest);
                }
                break;
            case 3:
                cout<<"\nEnter the root node :";
                cin>>root;
                A.BFS(root);
                break;
            case 4:
                exit(0);
            default:
                cout<<"\nInvalid Option";
        }
    }
}