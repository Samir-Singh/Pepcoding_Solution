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
        {
            st.pop();
        }
    }
    
    return root;
}

pair<int,int> tiltofTreeUtil(node *root)
{
    if(root == NULL)
    {
        pair<int,int> ans;
        ans.first = 0;
        ans.second = 0;
        return ans;
    }
    
    pair<int,int> left = tiltofTreeUtil(root->left);
    pair<int,int> right = tiltofTreeUtil(root->right);
    
    pair<int,int> ans;
    ans.first = left.first + right.first + root->data;
    ans.second = left.second+right.second + abs(left.first - right.first);
    
    return ans;
}

int tiltofTree(node *root)
{
    pair<int,int> ans = tiltofTreeUtil(root);
    return ans.second;
}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    node *root = constructTree(arr);
    cout<<tiltofTree(root);
}