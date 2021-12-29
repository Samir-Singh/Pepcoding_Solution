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
    pair<node*,int> p = {root, 1};
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
                pair<node*,int> lp = {newNode, 1};
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
                pair<node*,int> rp = {newNode, 1};
                st.push(rp);
            }
            idx++;
        }
        else
            st.pop();
    }
    
    return root;
}

void printsingleChild(node *root)
{
    if(!root)
        return;
    if(!root->left || !root->right)
    {
        if(root->left && !root->right)
            cout<<root->left->data<<endl;
        if(root->right && !root->left)
            cout<<root->right->data<<endl;
    }
    
    printsingleChild(root->left);
    printsingleChild(root->right);
}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    node *root = constructTree(arr);
    printsingleChild(root);
}