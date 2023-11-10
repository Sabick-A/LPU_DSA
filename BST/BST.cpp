#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left,*right;
    Node(int data)
    {
        this->data=data;
        this->left=this->right=NULL;
    }
};

class BST
{
    Node *root;
    int findMin(Node *root)
    {
        int min=root->data;
        while(root->left!=NULL)
        {
            root=root->left;
            min=root->data;
        }
        return min;

    }
    int findMax(Node *root)
    {
        int max=root->data;
        while(root->right!=NULL)
        {
            root=root->right;
            max=root->data;
        }
        return max;
        
    }
    Node* insertT(Node *root,int key)
    {
        if(root==NULL)
        {
            root=new Node(key);
            return root;
        }
        else if(key>root->data)
        {
            root->right=insertT(root->right,key);
        }
        else if(key<root->data)
        {
            root->left=insertT(root->left,key);
        }
        return root;
    }
    void inOrderT(Node *root)
    {
        if(root==NULL)
        {
            return;
        }
        inOrderT(root->left);
        cout<<root->data<<" -> ";
        inOrderT(root->right);
    }
    void preOrderT(Node *root)
    {
        if(root==NULL)
        {
            return;
        }
        cout<<root->data<<" -> ";
        preOrderT(root->left);
        preOrderT(root->right);
    }
    void postOrderT(Node *root)
    {
        if(root==NULL)
        {
            return;
        }
        postOrderT(root->left);
        postOrderT(root->right);
        cout<<root->data<<" -> ";
    }
    Node* deleteT(Node *root,int key)
    {
        if(root==NULL)
        {
            return root;
        }
        else if(key<root->data){root->left=deleteT(root->left,key);}
        else if(key>root->data){root->right=deleteT(root->right,key);}
        else
        {
            if(root->left==NULL)
            {
                return root->right;
            }
            else if(root->right==NULL)
            {
                return root->left;
            }
            else
            {
                root->data = findMin(root->right);
                root->right = deleteT(root->right, root->data);
            }
        }
        return root;
    }
    int heightT(Node *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=heightT(root->left);
        int r=heightT(root->right);
        return max(l,r)+1;
    }
    public:
    BST()
    {
        this->root=NULL;
    }
    void insert(int key)
    {
        this->root=insertT(this->root,key);
    }
    void inOrder()
    {
        inOrderT(this->root);
        cout<<"\n";
    }
    void preOrder()
    {
        preOrderT(this->root);
        cout<<"\n";
    }
    void postOrder()
    {
        postOrderT(this->root);
        cout<<"\n";
    }
    void del(int key) {
            this->root = deleteT(this->root, key);
    }
    int height()
    {
        return heightT(this->root);
    }
};

int main()
{
    int choice,value;
    BST A;
    while(1)
    {
        cout<<"Enter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter Value: ";
                cin>>value;
                A.insert(value);
                break;
            case 2:
                A.inOrder();
                break;
            case 3:
                A.preOrder();
                break;
            case 4:
                A.postOrder();
                break;
            case 5:
                cout<<"Enter Value: ";
                cin>>value;
                A.del(value);
                break;
            case 6:
                cout<<"height is : ";
                cout<<A.height();
                break;
            case 7:
                exit(0);
                break;
            default:
                cout<<"Invalid"<<"\n";
        }
    }
}