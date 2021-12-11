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
    stack<node*> st;
    node *root;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == -1)
            st.pop();
        else
        {
            node *newNode = new node(arr[i]);
            if(!st.empty())
                st.top()->children.push_back(newNode);
            else
                root = newNode;
            st.push(newNode);
        }
    }
    return root;
}

int nodeToRootPathUtil(node *root, int node, vector<int> &ans)
{
    if(root->data == node)
    {
        ans.push_back(root->data);
        return 1;
    }
    for(int i=0; i<root->children.size(); i++)
    {
        if(nodeToRootPathUtil(root->children[i], node, ans))
        {
            ans.push_back(root->data);
            return 1;
        }
    }
    return 0;
}

vector<int> nodeToRootPath(node *root, int node)
{
    vector<int> ans;
    nodeToRootPathUtil(root, node, ans);
    return ans;
}

int LCAofTree(node *root, int n1, int n2)
{
    vector<int> path1 = nodeToRootPath(root, n1);
    vector<int> path2 = nodeToRootPath(root, n2);
    
    int i=path1.size()-1;
    int j=path2.size()-1;
    
    while(i>=0 && j>=0 && path1[i] == path2[j])
    {
        i--;
        j--;
    }
    
    i++;
    j++;
    
    return (i+j);
}

int distancebwNodes(node *root, int node1, int node2)
{
    return LCAofTree(root, node1, node2);
}
int main()
{
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    node *root = createTree(arr);
    cout<<distancebwNodes(root, 50, 100);
}