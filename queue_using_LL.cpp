#include<bits/stdc++.h>

using namespace std;

struct QNode
{
    int data;
    QNode *next;
    QNode(int x)
    {
        data=x;
        this->next=NULL;
    }
};

class Queue
{
    QNode *front,*rear;
    public:
    Queue(){front=rear=NULL;}

    void enQueue(int x)
    {
        QNode *newNode=new QNode(x);
        if(rear==NULL)
        {
            front=rear=newNode;
            return;
        }
            rear->next=newNode;
            rear=newNode;
    }

    void deQueue()
    {
        if(front==NULL)
        {
            cout<<"Queue Empty";
            return;
        }
        QNode *temp=front;
        front=temp->next;
        if(front==NULL)
        {
            rear=NULL;
        }
        delete temp;
    }

    void Front()
    {
        if(front==NULL)
        {
            cout<<"Queue Empty"<<"\n";
            return;
        }
        cout<<"Front element is : "<<front->data<<"\n";
    }
    
    void Display()
    {
        if(front==NULL)
        {
            cout<<"Queue Empty"<<"\n";
            return;
        }
        QNode *temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
    }
};

int main()
{
    Queue q;
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