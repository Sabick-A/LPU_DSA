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

void print(Node *head){
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
}
int main(){
    Node *head=NULL;
    int n,element;
    cout<<"Enter Size of Linked List : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        insertAtBeg(&head,element);
    }
    print(head);
    return 0;
}