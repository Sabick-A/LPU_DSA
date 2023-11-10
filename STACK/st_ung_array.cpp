#include<iostream>
using namespace std;
class Stack
{
    int MAX;
    int *arr;
    int top;
    public:
    Stack(int size)
    {
        MAX=size;
        arr=new int[MAX];
        top=-1;
    }
    void push(int x);
    void pop();
    int topelement();
    bool isEmpty();
    bool isFull();
};

void Stack::push(int x)
{
    if(top==(MAX-1))
    {
        cout<<"STACK OVERFLOW";
        return;
    }
        arr[++top]=x;
        cout<<x<<" Pushed into Stack"<<"\n";
}

void Stack::pop()
{
    if(top==-1)
    {
        cout<<"Stack UNDERFLOW";
        return;
    }
    int x=arr[top--];
    cout<<x<<"Popped out of stack";
}

int Stack::topelement()
{
    if(top==-1)
    {
        cout<<"No elements in Stack";
        return 0;
    }
    int x=arr[top];
    return x;
}

bool Stack::isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    return false;
}

bool Stack::isFull()
{
    if(top==(MAX-1))
    {
        return true;
    }
    return false;
}

int main()
{
    Stack *st=new Stack(4);
    if(st->isEmpty())
    {
        cout<<"EMpty"<<"\n";
    }
    st->push(6);
    st->push(7);
    st->push(4);
    st->pop();
    st->push(3);
    cout<<st->topelement();
    st->push(5);
    st->push(6);
    if(st->isFull())
    {
        cout<<"FULL"<<"\n";
    }
    return 0;
}