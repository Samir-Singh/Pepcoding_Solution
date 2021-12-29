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

node *constructTree(vector<int> arr)
{
    node *root = new node(arr[0]);
    pair<node*,int> p = {root,1};
    stack<pair<node*,int>> st;
    st.push(p);
    
    int idx = 1;
    while(!st.empty())
    {
        if(st.top().second == 1)
        {
            st.top().second++;
            if(arr[idx] != -1)
            {
                node *newNode = new node(arr[idx]);
                st.top().first->left = newNode;
                pair<node*,int> lp = {newNode,1};
                st.push(lp);
            }
            idx++;
        }
        else if(st.top().second == 2)
        {
            st.top().second++;
            if(arr[idx] != -1)
            {
                node *newNode = new node(arr[idx]);
                st.top().first->right = newNode;
                pair<node*,int> rp = {newNode,1};
                st.push(rp);
            }
            idx++;
        }
        else
            st.pop();
    }
    
    return root;
}

void transformtoNormal(node *root)
{
    if(root == NULL)
        return;
        
    if(root->left)
    {
        node *temp = root->left;
        root->left = root->left->left;
        delete temp;
    }
    
    transformtoNormal(root->left);
    transformtoNormal(root->right);
}

void printTree(node *root)
{
    if(root == NULL)
        return;
    cout<<root->data<<"-> ";
    if(root->left)
        cout<<"L"<<root->left->data<<" ";
    if(root->right)
        cout<<"R"<<root->right->data;
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    vector<int> arr = {50,50,25,25,12,12,-1,-1,-1,-1,37,37,30,30,-1,-1,-1,-1,-1,-1,75,75,62,62,-1,-1,70,70,-1,-1,-1,-1,87,87,-1,-1,-1,-1};
    node *root = constructTree(arr);
    transformtoNormal(root);
    printTree(root);
}