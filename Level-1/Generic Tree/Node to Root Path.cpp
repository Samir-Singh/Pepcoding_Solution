#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    vector<node*> children;
    node(int data)
    {
        this->data = data;
    }
};

node *createTree(vector<int> arr)
{
    node *root;
    stack<node*> st;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == -1)
            st.pop();
        else
        {
            node *newNode = new node(arr[i]);
            if(st.empty())
                root = newNode;
            else
                st.top()->children.push_back(newNode);
            st.push(newNode);
        }
    }
    return root;
}

int find(node *root, int data, vector<int> &ans)
{
    if(root->data == data)
    {
        ans.push_back(root->data);
        return 1;
    }
    
    for(int i=0; i<root->children.size(); i++)
    {
        if(find(root->children[i], data, ans))
        {
            ans.push_back(root->data);
            return 1;
        }
    }
    return 0;
}

vector<int> nodeToRootPath(node *root, int data)
{
    vector<int> ans;
    find(root, data, ans);
    return ans;
}

int main()
{
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    node *root = createTree(arr);
    vector<int> ans = nodeToRootPath(root, 120);
    for(auto it : ans)
        cout<<it<<" ";
}