#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int n)
    {
        this->data=n;
        this->next=NULL;
    }
};

class Stack
{
    Node *top;
    public:
    Stack()
    {
        top=NULL;
    }

    void push(int x)
    {
        Node *temp=new Node(x);
        if(!temp)
        {
            cout<<"Stack overflow"<<"\n";
            return;
        }
        else
        {   
            temp->next=top;
            top=temp;
        }
        cout<<temp->data<<" pushed into stack"<<"\n";
    }

    void pop()
    {
        if(top==NULL)
        {
            cout<<"Stack Underflow"<<"\n";
            return;
        }
            Node *temp=top;
            cout<<temp->data<<" is popped out of stack"<<"\n";
            top=top->next;
            free(temp);
    }

    int TOS()
    {
        Node *temp=top;
        if(top==NULL)
        {
            cout<<"Stack Empty";
            return 0;
        }
            return top->data;

    }

};

int main()
{
    Stack st;
    st.push(2);
    st.pop();
    st.pop();
    st.push(3);
    st.push(4);
    cout<<st.TOS();
    return 0;
}