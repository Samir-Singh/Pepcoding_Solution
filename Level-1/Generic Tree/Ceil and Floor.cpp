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
    node *root;
    stack<node *> st;
    
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

void ceilAndFloorUtil(node *root, int key, int &Ceil, int &Floor)
{
    if(root->data > key && root->data < Ceil) Ceil = root->data;
    
    if(root->data < key && root->data > Floor) Floor = root->data;
    
    for(int i=0; i<root->children.size(); i++)
        ceilAndFloorUtil(root->children[i], key, Ceil, Floor);
}

void ceilAndFloor(node *root, int key)
{
    int Ceil = INT_MAX;
    int Floor = INT_MIN;
    ceilAndFloorUtil(root, key, Ceil, Floor);
    cout<<"Ceil : "<<Ceil<<endl;
    cout<<"Floor : "<<Floor;
}

int main()
{
    vector<int> arr = {8,4,2,-1,6,-1,-1,12,10,-1,14,-1,-1,-1};
    node *root = constructTree(arr);
    ceilAndFloor(root, 6);
}
