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

void printTree(node *root)
{
    queue<node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        int k = q.size();
        while(k--)
        {
            node *front = q.front();
            q.pop();
            cout<<front->data<<" ";
            for(int i=0; i<front->children.size(); i++)
                q.push(front->children[i]);
        }
        cout<<endl;
    }
}

void mirrorTree(node *root)
{
    for(int i=0; i<root->children.size(); i++)
        mirrorTree(root->children[i]);
        
    reverse(root->children.begin(), root->children.end());
}

int main()
{
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    node *root = createTree(arr);
    mirrorTree(root);
    printTree(root);
}