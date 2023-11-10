#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

void insertAtBeg(Node **head,int element)
{
    Node* newNode=new Node;
    newNode->data=element;
    newNode->next=(*head);
    newNode->prev=NULL;

    if((*head)!=NULL){
        (*head)->prev=newNode;
    }
    (*head)=newNode;
}

void insertatpos(Node **head,int element,int pos)
{
    Node *temp=*head;
    Node *newNode=new Node;
    newNode->data=element;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    newNode->prev=temp;
    newNode->next=NULL;
    if(temp->next!=NULL){
        newNode->next=temp->next;
        temp->next->prev=newNode;
    }
    temp->next=newNode;

}
void print(Node *head){
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
}
int main(){
    Node *head=NULL;
    int n,element,pos;
    cout<<"Enter Size of Linked List : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        insertAtBeg(&head,element);
    }
    cout<<"\n\n\tEnter the Position you want to enter: ";
    cin>>pos;
    cout<<"\n\n\tEnter the Element: ";
    cin>>element;
    insertatpos(&head,element,pos);
    cout<<"LinkedListAfter Insertion\n";
    print(head);
    return 0;
}