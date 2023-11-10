#include<stack>
#include<iostream>
using namespace std;

int prec(char c)
{   
    if(c =='^')
    {
        return 3;
    }
    else if ((c=='*')||(c=='/'))
    {
        return 2;
    }
    else if ((c=='+')||(c=='-'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void itop(string exp)
{
    stack <char> st;
    st.push('@');
    int l=exp.length();
    string ns;
    for(int i=0;i<l;i++)
    {
    if((exp[i]>='a' && exp[i]<='z')||(exp[i]>='A' && exp[i]<='Z'))
    {
        ns+=exp[i];
    }
    else if (exp[i]=='(')
    {
        st.push('(');
    }
    else if (exp[i]==')')
    {
        while(st.top()!='(' && st.top()!='@')
        {
            ns+=st.top();
            st.pop();
        
        }
        if(st.top()=='(')
        {
            st.pop();
        }
    }
    else 
    {
        while(st.top()!='@'&& (prec(exp[i])<=prec(st.top())))
        {
            ns+=st.top();
            st.pop();
        }
        st.push(exp[i]);
    }
    }
    while(st.top()!='@')
    {
        ns+=st.top();
        st.pop();
    }
    cout<<ns;
}
int main()
{
    string exp;
    cin>>exp;
    itop(exp);
    return 0;
}