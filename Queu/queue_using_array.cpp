#include<iostream>

using namespace std;

class Queue
{

    int size;
    int *arr;
    int rear;
    public:
    Queue(int x)
    {
        size=x;
        arr=new int[size];
        rear=-1;
    }
    void enQueue(int x)
    {
        if(rear==(size-1))
        {
            cout<<"Queue Full"<<"\n";
            return;
        }
        else
        {
            arr[++rear]=x;
            cout<<x<<" inserted "<<"\n";
        }
    }

    void deQueue()
    {
        if(rear==-1)
        {
            cout<<"Queue Empty"<<"\n";
            return;
        }
        else
        {
            cout<<arr[0]<<"popped out"<<"\n";
            for(int i=0;i<rear;i++)
            {
                arr[i]=arr[i+1];
            }
            rear--;
        }
    }

    void Display()
    {
        if(rear==-1)
        {
            cout<<"Queue Empty"<<"\n";
            return;
        }
        for(int i=0;i<=rear;i++)
        {
            cout<<arr[i]<<" -> ";
        }
    }
    void Front()
    {
        if(rear==-1)
        {
            cout<<"Queue Empty"<<"\n";
            return;
        }
        cout<<"Element at Front is "<<arr[0];
    }
};

int main()
{
    Queue q(4);
    int choice,value;
    while(1)
    {
    cout<<"\n"<<"Enter a choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        cin>>value;
        q.enQueue(value);
        break;
    case 2:
        q.deQueue();
        break;
    case 3:
        q.Front();
        break;
    case 4: 
        q.Display();
        break;
    case 5:
        exit(0);
        break;
    default:
        break;
    }
    }
    return 0;
}