#include<iostream>
using namespace std;

void pyramid(int n)
{
    for (int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<" * ";
        }
        cout<<"\n";
    }
}

int main()
{
    int rows;
    cout<<"Enter the rows : ";
    cin>>rows;
    pyramid(rows);
    return 0;
}