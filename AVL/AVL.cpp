#include<iostream>
using namespace std;

struct Node
{
    int key,height;
    Node *left,*right;
};
 
Node* newNode(int key)
{
    Node *newNode=new Node();
    newNode->key=key;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->height=0;
    return newNode;
}

int getHeight(Node *node)
{
    if(node==NULL)
    {
        return 0;
    }
    return node->height;
}

int max (int a,int b)
{
    return (a > b)?a :b ;
}

Node *rightRotate(Node *y)
{
    Node *x=y->left;
    Node *T2=x->right;

    x->right=y;
    y->left=T2;

    y->height=max(getHeight(y->right),getHeight(y->left))+1;
    x->height=max(getHeight(x->right),getHeight(x->left))+1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y=x->right;
    Node *T1=y->left;

    y->left=x;
    x->right=T1;

    x->height=max(getHeight(x->right),getHeight(x->left))+1;
    y->height=max(getHeight(y->right),getHeight(y->left))+1;

    return y;
}

int getBalance(Node *N)
{
    if(N==NULL)
    {
        return 0;
    }
    return getHeight(N->left)-getHeight(N->right);
}

Node *insertNode(Node *node, int key)
{
    if(node==NULL)
    {
        return (newNode(key));
    }
    else if(key>node->key)
    {
        node->right=insertNode(node->right,key);
    }
    else if(key<node->key)
    {
        node->left=insertNode(node->left,key);
    }
    else
    {
        return node;
    }
   
    node->height=1+max(getHeight(node->right),getHeight(node->left));
    
    int bf=getBalance(node);

    if(bf>1 && key<node->left->key)
    {
        return rightRotate(node);
    }
    if(bf<-1 && key>node->right->key)
    {
        return leftRotate(node);
    }
    if (bf<-1 &&key<node->right->key)
    {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }
    if(bf>1 && key>node->left->key)
    {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    
    return node;

}

Node* minValueNode(Node* node)
{
    Node *current=node;
    while(current->left !=NULL)
    {
        current=current->left;
    }
    return current;
}
Node *deleteNode(Node* root,int key)
{
    if(root==NULL)
    {
        return root;
    }
    else if(key>root->key)
    {
        root->right=deleteNode(root->right,key);
    }
    else if(key<root->key)
    {
        root->left=deleteNode(root->left,key);
    }
    else
    {
        if((root->left==NULL) || (root->right==NULL))
        {
            Node *temp=root->left?root->left:root->right;

            if(temp==NULL)
            {
                temp=root;
                root=NULL;
            }

            else
            {
                *root=*temp;
            }
            delete temp;

        }
        else
        {
            Node *temp=minValueNode(root->right);

            root->key=temp->key;
            root->right=deleteNode(root->right,temp->key);
        }

        if(root==NULL)
        {
            return root;
        }

        root->height=1+(max(getHeight(root->right),getHeight(root->left)));

    int balance=getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) 
        return rightRotate(root); 
 
    // Left Right Case 
    if (balance > 1 && 
        getBalance(root->left) < 0) 
    { 
        root->left = leftRotate(root->left); 
        return rightRotate(root); 
    } 
 
    // Right Right Case 
    if (balance < -1 && 
        getBalance(root->right) <= 0) 
        return leftRotate(root); 
 
    // Right Left Case 
    if (balance < -1 && 
        getBalance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
    }
    return root;
}

void inOrder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->key<<" - ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->key<<" - ";
}

int main()
{
    Node *root=NULL;

    int n,key;
    while(1)
    {
    cin>>n;
    switch (n)
    {
        case 1:
            cout<<"\nEnter KEy : ";
            cin>>key;
            root=insertNode(root,key);
            break;
        case 2:
            cout<<"\nEnter key to delete : ";
            cin>>key;
            root=deleteNode(root,key);
            break;
        case 3:
            cout<<"Inorder Traversal is : ";
            inOrder(root);
            break;
        case 4:
            cout<<"PostOrder Traversal is : ";
            postOrder(root);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout<<"Invalid Choice\n";
    }
    }    
    return 0;
}