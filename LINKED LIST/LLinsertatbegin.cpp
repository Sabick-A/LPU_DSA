#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void insertatbeg_LL(struct Node **head_ref,int element)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->next=*head_ref;
    newNode->data =element ;
    *head_ref=newNode;
}

void printLL(struct Node *head)
{
    struct Node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
    
}
int main()
{
    int size,element;
    cin>>size;
    struct Node *head=NULL; 
    for(int i=0;i<size;i++)
    {
        cin>>element;
        insertatbeg_LL(&head,element);
    }
    printLL(head);
}