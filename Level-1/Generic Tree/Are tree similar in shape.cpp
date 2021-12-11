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

int areTreeSimilar(node *root1, node *root2)
{
    if(root1->children.size() != root2->children.size())
        return false;
    
    for(int i=0; i<root1->children.size(); i++)
    {
        if(areTreeSimilar(root1->children[i], root2->children[i]) == false)
            return false;
    }
    
    return true;
}

int main()
{
    vector<int> arr1 = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    vector<int> arr2 = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    node *root = createTree(arr1);
    node *root2 = createTree(arr2);
    cout<<areTreeSimilar(root, root2);
}