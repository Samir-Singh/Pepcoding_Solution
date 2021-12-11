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
            if(st.empty())
                root = newNode;
            else
                st.top()->children.push_back(newNode);
            st.push(newNode);
        }
    }
    return root;
}

int areTreeMirror(node *root1, node *root2)
{
    if(root1->children.size() != root2->children.size())
        return false;
    
    for(int i=0; i<root1->children.size(); i++)
    {
        if(areTreeMirror(root1->children[i], root2->children[root2->children.size()-i-1]) == false)
            return false;
    }
    
    return true;
}

int main()
{
    vector<int> arr1 = {10,20,-1,30,50,-1,60,-1,-1,40,-1,-1};
    vector<int> arr2 = {100,200,-1,300,500,-1,600,-1,-1,400,-1,-1};
    node *root = createTree(arr1);
    node *root2 = createTree(arr2);
    cout<<areTreeMirror(root, root2);
}