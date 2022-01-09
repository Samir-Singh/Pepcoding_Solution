#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;
    node(int data)
    {
        this->data = data;
    }
};

node *constructTree(vector<int> arr, int lo, int hi)
{
    if(lo > hi)
        return NULL;

    int mid = (lo+hi)/2;
    node *root = new node(arr[mid]);
    root->left = constructTree(arr, lo, mid-1);
    root->right = constructTree(arr, mid+1, hi);

    return root;
}

node *addNode(node *root, int x)
{
    if(root == NULL)
    {
        node *newNode = new node(x);
        return newNode;
    }

    if(x < root->data)
        root->left = addNode(root->left, x);
    else
        root->right = addNode(root->right, x);

    return root;
}

void displayTree(node *root)
{
    if(root == NULL)
        return;

    cout<<root->data<<"-> ";
    if(root->left)
        cout<<"L"<<root->left->data<<" ";
    if(root->right)
        cout<<"R"<<root->right->data;
    cout<<endl;

    displayTree(root->left);
    displayTree(root->right);
}

int main()
{
    vector<int> arr = {12,25,30,37,40,50,62,75,87};
    node *root = constructTree(arr, 0, arr.size()-1);
    root = addNode(root, 10);
    displayTree(root);
}
