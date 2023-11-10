#include<bits/stdc++.h>

using namespace std;

class PQueue
{
    struct Task 
    {
        string name;
        int priority;
    };
    Task *queue;
    int rear,size;
    public:
    PQueue(int n)
    {
        size=n;
        queue=new Task[n];
        rear=-1;
    }

    void insert(string n,int p)
    {
        if(rear==size-1)
        {
            cout<<"queue full"<<"\n";
            return;
        }
        if(rear==-1)
        {
            rear++;
            queue[rear].name=n;
            queue[rear].priority=p; 
            return;
        }
        int i=rear;
            while(i>=0 && queue[i].priority>p)
            {
                queue[i+1]=queue[i];
                i--;
            }
        queue[i+1].name=n;
        queue[i+1].priority=p;
        rear++;
    }

    void display()
    {   if(rear==-1)
       {
            cout<<"Queue Empty"<<"\n";
            return;
        }
        for(int i=0;i<=rear;i++)
        {
            cout<<"( "<<queue[i].name<<" , "<<queue[i].priority<<" ) "<<" -> ";
        }
    }
};

int main()
{
    PQueue q(4);
    int choice,p;
    string n;
    while(1)
    {
        cin>>choice;
        switch(choice)
        {
            case 1: 
                cout<<"Enter : ";
                cin>>n;
                cout<<"\n"<<"Enter p: ";
                cin>>p;
                q.insert(n,p);
                break;
            case 2:
                q.display();
                break;
            case 3:
                exit(0);
                break;
        }
    }
}