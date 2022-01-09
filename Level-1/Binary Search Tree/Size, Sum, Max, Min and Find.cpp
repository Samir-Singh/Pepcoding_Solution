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

int size(node *root)
{
    if(root == NULL)
        return 0;
    return 1+size(root->left)+size(root->right);
}

int sum(node *root)
{
    if(root == NULL)
        return 0;
    return root->data+sum(root->left)+sum(root->right);
}

int max(node *root)
{
    if(root == NULL)
        return -1;

    node *temp = root;
    while(temp->right)
        temp = temp->right;

    return temp->data;
}

int min(node *root)
{
    if(root == NULL)
        return -1;

    node *temp = root;
    while(temp->left)
        temp = temp->left;

    return temp->data;
}

int find(node *root, int x)
{
    if(root == NULL)
        return 0;

    if(root->data == x)
        return 1;

    if(root->data < x)
        return find(root->right, x);

    return find(root->left, x);
}

int main()
{
    vector<int> arr = {12,25,37,50,62,75,87};
    node *root = constructTree(arr, 0, arr.size()-1);
    cout<<"Size : "<<size(root)<<endl;
    cout<<"Sum : "<<sum(root)<<endl;
    cout<<"Max : "<<max(root)<<endl;
    cout<<"Min : "<<min(root)<<endl;
    cout<<"Find : "<<find(root, 87);
}
