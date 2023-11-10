#include<iostream>
using namespace std;

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

class minHeap
{
    int *arr;
    int capacity,size;

    public:

    minHeap(int cap)
    {
        capacity=cap;
        arr=new int[capacity];
        size=0;
    }

    ~minHeap()
    {
        delete[] arr;
    }

    int parent(int i) { return (i-1)/2; }
    int left(int i) { return i*2+1; }
    int right(int i) { return i*2+2; }

    void minHeapify(int i)
    {
        int l=left(i);
        int r=right(i);

        int smallest=i;

        if(l<size && arr[l]<arr[smallest])
        {
            smallest=l;
        }
        if(r<size && arr[r]<arr[smallest])
        {
            smallest=r;
        }
        if(smallest!=i)
        {
            swap(&arr[i],&arr[smallest]);
            minHeapify(smallest);
        }
    }

    void insertKey(int key)
    {
        if(size==capacity)
        {
            cout<<"Heap is full"<<endl;
            return;
        }
        int i=size;
        arr[i]=key;
        size++;
        while(i!=0 && arr[parent(i)]>arr[i])
        {
            swap(&arr[i],&arr[parent(i)]);
            i=parent(i);
        }
    }

    void extractndel()
    {
        if(size==0)
        {
            cout<<"Heap is empty"<<endl;
            return;
        }
        else if(size == 1)
        {
            cout<<arr[0]<<" is deleted"<<endl;
            size--;
            return;
        }

        int t=arr[0];
        swap(&arr[0],&arr[size-1]);
        size--;
        minHeapify(0);
        cout<<t<<" is deleted"<<endl;
    }

    void display()
    {
        cout<<"The elements in Heap are :";
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    
    int peek()
    {
        if(size==0)
        {
            cout<<"Heap is empty"<<endl;
            return -1;
        }
        return arr[0];
    }

    void reduce(int i,int key)
    {
        if(i>=size || i<0)
        {
            cout<<"Invalid Index"<<endl;
            return;
        }
        if(key<arr[i])
        {
        arr[i]=key;
        while(i>=0 && arr[parent(i)]>arr[i])
        {
            swap(&arr[i],&arr[parent(i)]);
            i=parent(i);
        }
        }
        else
        {
            cout<<arr[i]<<"is less than "<<key<<endl;
            return;
        }
    }
};

int main()
{
    int key,choice,cap;
    cout<<"Enter size of Heap: ";
    cin>>cap;
    minHeap x(cap);
    while(1)
    {
        cout<<"Enter a choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter Key to insert : ";
                cin>>key;
                x.insertKey(key);
                break;
            case 2:
                x.extractndel();
                break;
            case 3:
                int m;
                m=x.peek();
                cout<<"The top element is "<<m<<endl;
                break;
            case 4:
                int i;
                cout<<"Enter the index: ";
                cin>>i;
                cout<<"Enter the reduced value: ";
                cin>>key;
                x.reduce(i,key);
                break;
            case 5:
                x.display();
                break;
            case 6:
                exit(0);
                break;
            default:
                cout<<"Invalid Option "<<endl;
                break;
        }
    }
    return 0;
}