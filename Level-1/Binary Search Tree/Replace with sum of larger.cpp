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
                pair<node*,int> lp = {newNode, 1};
                st.top().first->left = newNode;
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
                pair<node*,int> rp = {newNode, 1};
                st.top().first->right = newNode;
                st.push(rp);
            }
            idx++;
        }
        else
            st.pop();
    }

    return root;
}

void replaceUtil(node *root, int &sum)
{
    if(root == NULL)
        return;

    replaceUtil(root->right, sum);

    int temp = root->data;
    root->data = sum;
    sum = sum+temp;

    replaceUtil(root->left, sum);
}

void replace(node *root)
{
    int sum = 0;
    replaceUtil(root, sum);
}

void printTree(node *root)
{
    if(root == NULL)
        return;

    cout<<root->data<<"-> ";
    if(root->left)
        cout<<"L"<<root->left->data<<" ";
    if(root->right)
        cout<<"R"<<root->right->data;
    cout<<endl;

    printTree(root->left);
    printTree(root->right);
}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,-1,-1,75,62,-1,-1,87,-1,-1};
    node *root = constructTree(arr);
    replace(root);
    printTree(root);
}
