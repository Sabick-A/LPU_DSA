#include<bits/stdc++.h>
using namespace std;

int TOH(int n,char src,char aux,char dest)
{
    if(n==1)
    {
        cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<"\n";
        return 1;
    }
    int m1=TOH(n-1,src,dest,aux);
    cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<"\n";
    int m2=TOH(n-1,aux,src,dest);
    return m1+m2+1;
}

int main()
{   int n;
    n=TOH(3,'A','B','C');
    cout<<"Total Moves :"<<n;
    return 0;
}

