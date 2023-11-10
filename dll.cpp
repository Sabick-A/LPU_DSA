#include<iostream>
using namespace std;

struct Node{
    public:
    int value;
    Node *next;
    Node *prev;
};

void insertFront(Node **head,int x)
{
    Node *newNode=new Node;
    newNode->value=x;
    newNode->next=(*head);
    newNode->prev=NULL;
    if((*head)!=NULL)
    {
        (*head)->prev=newNode;
    }
    *head=newNode;
}

void insertEnd(Node **head,int x)
{
    Node *newNode=new Node;
    newNode->value=x;
    newNode->next=NULL;
    if(*head==NULL)
    {
        *head=newNode;
    }
    else
    {
    Node *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    }


}

void insertatpos(Node **head,int pos,int x)
{

    Node *newNode=new Node;
    newNode->value=x;
    newNode->prev=NULL;
    if(pos==1)
    {
        newNode->next=*head;
        (*head)->prev=newNode;
        *head=newNode;
    }
    else
    {
    Node *temp=*head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    newNode->next=temp->next;
    if(temp->next!=NULL)
    {
        temp->next->prev=newNode;
    }
    
    temp->next=newNode;
    newNode->prev=temp;

    }
}

void deleteFront(Node **head)
{
    if(*head ==nullptr)
    {
        return;
    }
    Node *temp=*head;

    *head=(*head)->next;
    (*head)->prev=NULL;
    delete(temp);
}

void deleteEnd(Node **head)
{
    if(*head==nullptr)
    {
        return;
    }
    if((*head)->next==NULL)
    {
        delete *head;
        *head=NULL; 
        return;
    }
    Node *temp=*head;
    while(temp->next->next !=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}
void deletePos(Node **head,int pos)
{
    if(*head==nullptr)
    {
        return;
    }
    if(pos==1)
    {
    if((*head)->next==NULL)
    {
        delete *head;
        *head=NULL; 
        return;
    }
    else
    {   
        *head=(*head)->next;
        (*head)->prev=*head;
        return;
    }
    }
    Node *temp=*head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    temp->next->prev=temp;
}
void printLL(Node *head)
{   cout<<"Linked list is : ";
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->value<<" -> ";
        temp=temp->next;
    }
}
void reversePrint(Node *head)
{
    if(head==nullptr)
    {
        return;
    }
    reversePrint(head->next);

    cout<<head->value<<" -> ";
    return;

}
int main()
{
    Node *head=NULL;
    int choice;
    cout<<"\n\n" ;
    cout<<"Operations on LinkedList: "<<"\n";
    cout<<"\t"<<"1.Insert at Front"<<"\n";
    cout<<"\t"<<"2.Insert at End"<<"\n";
    cout<<"\t"<<"3.Insert at position"<<"\n";
    cout<<"\t"<<"4.Delete Front"<<"\n";
    cout<<"\t"<<"5.Delete End"<<"\n";
    cout<<"\t"<<"6.Delete at Pos"<<"\n";
    cout<<"\t"<<"7.Print the LL"<<"\n";
    cout<<"\t"<<"8.Print the LL in reverse"<<"\n";
    cout<<"\t"<<"9.Exit"<<"\n";
    while(1)
    {
    cout<<"\n"<<"Enter Your Choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            int value;
            cout<<"Enter a value to enter: ";
            cin>>value;
            insertFront(&head,value);
            break;
        case 2:
            int v;
            cout<<"Enter a value to enter: ";
            cin>>v;
            insertEnd(&head,v);
            break;
        case 3:
            int pos,va;
            cout<<"Enter the Value: ";
            cin>>va;
            cout<<"\n"<<"Enter the position you want to enter: ";
            cin>>pos;
            insertatpos(&head,pos,va);
            break;
        case 4:
            deleteFront(&head);
            break;
        case 5:
            deleteEnd(&head);
            break;
        case 6:
            int posi;
            cout<<"Enter Position: ";
            cin>>posi;
            deletePos(&head,posi);
            break;
        case 7:
            printLL(head);
            break;
        case 8:
            cout<<"Linked List is : ";
            reversePrint(head);
            break;
        case 9:
            exit(0);
            break;
        default:
            cout<<"Invalid Choice";
    }
    }
    return 0;
}