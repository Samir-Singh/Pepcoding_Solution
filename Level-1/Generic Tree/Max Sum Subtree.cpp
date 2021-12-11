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

void maxSumNodeUtil(node *root, int &maxSum, int &maxNode)
{
    int sum = root->data;
    for(int i=0; i<root->children.size(); i++)
        sum = sum+root->children[i]->data;
    
    if(sum > maxSum)
    {
        maxSum = sum;
        maxNode = root->data;
    }
    
    for(int i=0; i<root->children.size(); i++)
        maxSumNodeUtil(root->children[i], maxSum, maxNode);
}

void maxSumNode(node *root)
{
    int maxSum = INT_MIN;
    int maxNode = -1;
    maxSumNodeUtil(root, maxSum, maxNode);
    cout<<maxNode<<"@"<<maxSum;
}

int main()
{
    vector<int> arr = {10, 20, -50, -1, 60, -1, -1, 30, 70, -1, -80, 110, -1, -120, -1, -1, 90, -1, -1, 40, -100, -1, -1, -1};
    node *root = createTree(arr);
    maxSumNode(root);
}