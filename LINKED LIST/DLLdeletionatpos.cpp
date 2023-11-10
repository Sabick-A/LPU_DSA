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

void deleteatpos(Node *head,int pos)
{
    Node *temp=head;
    for(int i=1;i<pos;i++)
    {
        temp=temp->next;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
    }
    else{
        temp->prev->next=NULL;
    }
    delete(temp);
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
    cout<<"\n\n\tLinkedList before Deletion: ";
    print(head);
    cout<<"\n\n\tEnter the Position you want to delete: ";
    cin>>pos;
    deleteatpos(head,pos);
    cout<<"\n\n\tLinkedList After Deletion: ";
    print(head);
    return 0;
}