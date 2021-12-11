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

void getFloorUtil(node *root, int &Floor, int key)
{
    if(root->data < key && root->data > Floor)
        Floor = root->data;
    
    for(int i=0; i<root->children.size(); i++)
        getFloorUtil(root->children[i], Floor, key);
}

int getFloor(node *root, int key)
{
    int Floor = INT_MIN;
    getFloorUtil(root,Floor,key);
    return Floor;
}

int kthLargest(node *root, int k)
{
    int key = INT_MAX;
    for(int i=0; i<k; i++)
    {
        int temp = getFloor(root, key);
        key = temp;
    }
    return key;
}

int main()
{
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    node *root = createTree(arr);
    int k = 3;
    cout<<kthLargest(root,k);
}