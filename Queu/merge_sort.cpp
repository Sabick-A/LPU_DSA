#include<bits/stdc++.h>

using namespace std;

void merge(int arr[],int l,int m,int h)
{
    int n1=m-l+1;
    int n2=h-m;

    int arr1[n1];
    int arr2[n2];

    for(int i=0;i<n1;i++)
    {
        arr1[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        arr2[j]=arr[j+m+1];
    }

    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[k]=arr1[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=arr2[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int m=(l+h)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}

int main()
{
    int a[]={1,7,6,9,2,5};
    int size=sizeof(a)/sizeof(a[0]);
    mergeSort(a,0,size-1);
    cout<<"Sorted Array : ";
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
}