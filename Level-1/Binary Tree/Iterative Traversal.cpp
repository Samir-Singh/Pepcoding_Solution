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
    pair<node*, int> p = {root, 1};
    stack<pair<node*, int>> st;
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
                pair<node*, int> lp = {newNode, 1};
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
                pair<node*, int> rp = {newNode, 1};
                st.push(rp);
            }
            idx++;
        }
        else
            st.pop();
    }
    
    return root;
}

void iterativeTraversalUtil(node *root, vector<int> &pre, vector<int> &post, vector<int> &in)
{
    pair<node*,int> p = {root, 1};
    stack<pair<node*,int>> st;
    st.push(p);
    
    while(!st.empty())
    {
        if(st.top().second == 1)
        {
            pre.push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->left)
                st.push({st.top().first->left, 1});
        }
        else if(st.top().second == 2)
        {
            in.push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->right)
                st.push({st.top().first->right, 1});
        }
        else
        {
            post.push_back(st.top().first->data);
            st.pop();
        }
    }
}
void iterativeTraversal(node *root)
{
    vector<int> pre, post, in;
    iterativeTraversalUtil(root, pre, post, in);
    for(auto it : pre)
        cout<<it<<" ";
    cout<<endl;
    for(auto it : post)
        cout<<it<<" ";
    cout<<endl;
    for(auto it : in)
        cout<<it<<" ";
}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    node *root = constructTree(arr);
    iterativeTraversal(root);
}