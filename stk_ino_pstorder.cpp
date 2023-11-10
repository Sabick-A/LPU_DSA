#include<iostream>
#include<stack>

using namespace std;

int prec(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='+'|| c=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void Topostorder(string s)
{
    stack<char> st;
    int size=s.length();
    for(int i=0;i<size;i++)
    {
        if((s[i]>='A'&&s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
        {
            cout<<s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(st.top()!='(')
            {
                cout<<st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if(st.size()==0 ||(prec(s[i])>=prec(st.top())))
            {
                st.push(s[i]);
            }
            else
            {
                while(prec(st.top())>prec(s[i]))
                {
                    cout<<st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    while(st.size()!=0)
    {
        cout<<st.top();
        st.pop();
    }
}

int main()
{
    string s="D+(A+B*C)/(B*C)";
    Topostorder(s);
    return 0;
}