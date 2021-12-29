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

void rootToLeaf(node *root, int lo, int hi, string path, int sum)
{
    if(root == NULL)
        return;
    
    if(!root->left && !root->right)
    {
        path = path + to_string(root->data);
        sum = sum + root->data;
        if(sum >= lo && sum <= hi)
            cout<<path<<endl;
        return;
    }
    
    rootToLeaf(root->left, lo, hi, path+to_string(root->data)+" ", sum+root->data);
    rootToLeaf(root->right, lo, hi, path+to_string(root->data)+" ", sum+root->data);
}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,40,-1,-1,75,62,60,-1,-1,70,-1,-1,87,-1,-1};
    node *root = constructTree(arr);
    rootToLeaf(root, 150, 250, "", 0);
}