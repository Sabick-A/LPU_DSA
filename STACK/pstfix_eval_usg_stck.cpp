#include<bits/stdc++.h>
#include<stack>

using namespace std;

int implement(string exp)
{
    stack<int> st;
    for(int i=0;i<exp.length();i++)
    {
        if(isdigit(exp[i]))
        {
            st.push(exp[i]-'0');
        }
        else
        {
            int v1=st.top();
            st.pop();
            int v2=st.top();
            st.pop();
            switch (exp[i])
            {
            case '+':
                st.push(v2+v1);
                break;
            case '-':
                st.push(v2-v1);
                break;
            case '*':
                st.push(v2*v1);
                break;
            case '/':
                st.push(v2/v1);
                break;
            case '^':
                st.push(v2^v1);
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string s="123*+";
    cout<<implement(s);
    return 0;
}