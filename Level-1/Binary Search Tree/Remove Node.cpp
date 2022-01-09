#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;
    node(int data)
    {
        this->data = data;
    }
};

node *constructTree(vector<int> arr)
{
    node *root = new node(arr[0]);
    pair<node*,int> p = {root, 1};
    stack<pair<node*,int>> st;
    st.push(p);

    int idx = 1;
    while(!st.empty())
    {
        if(st.top().second == 1)
        {
            st.top().second++;
            if(arr[idx] != -1)
            {
                node *newNode = new node(arr[idx]);
                st.top().first->left = newNode;
                pair<node*,int> lp = {newNode, 1};
                st.push(lp);
            }
            idx++;
        }
        else if(st.top().second == 2)
        {
            st.top().second++;
            if(arr[idx] != -1)
            {
                node *newNode = new node(arr[idx]);
                st.top().first->right = newNode;
                pair<node*,int> rp = {newNode, 1};
                st.push(rp);
            }
            idx++;
        }
        else
            st.pop();
    }

    return root;
}

int max(node *root)
{
    if(root == NULL)
        return -1;

    node *temp = root;
    while(temp->right != NULL)
        temp = temp->right;

    return temp->data;
}

void displayTree(node *root)
{
    if(root == NULL)
        return;
    cout<<root->data<<"-> ";
    if(root->left)
        cout<<"L"<<root->left->data<<" ";
    if(root->right)
        cout<<"R"<<root->right->data;
    cout<<endl;

    displayTree(root->left);
    displayTree(root->right);
}

node *removeNode(node *root, int val)
{
    if(root == NULL)
        return NULL;

    else if(val < root->data)
        root->left = removeNode(root->left, val);

    else if(val > root->data)
        root->right = removeNode(root->right, val);

    else
    {
        if(root->left && root->right)
        {
            int temp = max(root->left);
            root->data = temp;
            root->left = removeNode(root->left, temp);
        }
        else if(root->left)
            return root->left;
        else
            return root->right;
    }

    return root;
}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,40,-1,-1,75,62,-1,-1,87,-1,-1};
    node *root = constructTree(arr);
    root = removeNode(root, 50);
    displayTree(root);
}
