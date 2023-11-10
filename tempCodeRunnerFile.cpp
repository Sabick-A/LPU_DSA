#include<iostream>
using namespace std;

int main()
{
    int arr[10];
    int ind=0;
    int num;
    while(ind<10 && cin>>num)
    {
        arr[ind++]=num;
    }
    for(int i=0;i<ind;i++)
    {
        cout<<arr[i]<<" ";
    }
}