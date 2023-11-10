#include<iostream>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
};

void insert_at_end(struct Node **head_ref,int element)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=element;
    newNode->next=NULL;
    if(*head_ref==NULL)
    {
        *head_ref=newNode;
        return;
    }
    else
    {
        struct Node *temp=*head_ref;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void printLL(struct Node *head)
{
    struct Node *temp=head;
    cout<<"\n\nElements in Linkedlist are: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    int n,element;
    cout<<"  Enter the size of linkedlist : ";
    cin>>n;
    struct Node *head=NULL;
    for(int i=0;i<n;i++){
        cout<<"\n Enter element "<<i+1<<" : ";
        cin>>element;
        insert_at_end(&head,element);
    }
    printLL(head);
}