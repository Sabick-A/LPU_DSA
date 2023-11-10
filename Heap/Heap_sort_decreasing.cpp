#include<iostream>
using namespace std;

void Heapify(int arr[],int size,int i)
{
    int l=2*i+1;
    int r=2*i+2;

    int smallest=i;
    if(l<size && arr[l]<arr[smallest])
    {
        smallest=l;
    }
    if(r<size && arr[r]<arr[smallest])
    {
        smallest=r;
    }
    if(smallest != i)
    {
        swap(arr[i],arr[smallest]);
        Heapify(arr,size,smallest);
    }

}

void Heapsort(int arr[],int size)
{
    for(int i=size/2-1;i>=0;i--)
    {
        Heapify(arr,size,i);
    }

    for(int i=size-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        Heapify(arr,i,0);
    }
}

void printArray(int arr[],int n)
{
    cout<<"Elements in array is  : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int arr[]={1,6,2,5,7,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    Heapsort(arr,n);
    printArray(arr,n);
    return 0;
}
