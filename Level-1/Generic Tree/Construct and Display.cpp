#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    vector<node *> children;
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

void printTree(node *root)
{
    cout<<root->data<<"-> ";
    for(int i=0; i<root->children.size(); i++)
        cout<<root->children[i]->data<<" ";
    
    cout<<endl;
    for(int i=0; i<root->children.size(); i++)
        printTree(root->children[i]);
}

int main()
{
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    node *root = createTree(arr);
    printTree(root);
}