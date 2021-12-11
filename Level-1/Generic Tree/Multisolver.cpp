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

node *constructTree(vector<int> arr)
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

void multisolverUtil(node *root, int depth, int &size, int &min1, int &max1, int &height)
{
    size++;
    min1 = min(min1, root->data);
    max1 = max(max1, root->data);
    height = max(depth, height);
    
    for(int i=0; i<root->children.size(); i++)
        multisolverUtil(root->children[i], depth+1, size, min1, max1, height);
}

void multisolver(node *root)
{
    int size = 0;
    int min1 = INT_MAX;
    int max1 = INT_MIN;
    int height = 0;
    multisolverUtil(root, 0, size, min1, max1, height);
    cout<<"Size : "<<size<<endl;
    cout<<"Min : "<<min1<<endl;
    cout<<"Max : "<<max1<<endl;
    cout<<"Height : "<<height;
}

int main()
{
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    node *root = constructTree(arr);
    multisolver(root);
}