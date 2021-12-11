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

void levelWiseZigZag(node *root)
{
    stack<node*> st1;
    stack<node*> st2;
    st1.push(root);
    
    while(!st1.empty() || !st2.empty())
    {
        while(!st1.empty())
        {
            node *front = st1.top();
            st1.pop();
            cout<<front->data<<" ";
            for(int i=0; i<front->children.size(); i++)
                st2.push(front->children[i]);
        }
        cout<<endl;
            
        while(!st2.empty())
        {
            node *front = st2.top();
            st2.pop();
            cout<<front->data<<" ";
            for(int i=front->children.size()-1; i>=0; i--)
                st1.push(front->children[i]);
        }
        cout<<endl;
    }
}

int main()
{
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    node *root = createTree(arr);
    levelWiseZigZag(root);
}