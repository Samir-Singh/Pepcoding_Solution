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

int nodetoRootPathUtil(node *root, int data, vector<node*> &ans)
{
    if(root == NULL)
        return 0;
        
    if(root->data == data)
    {
        ans.push_back(root);
        return 1;
    }
    
    if(nodetoRootPathUtil(root->left, data, ans) || nodetoRootPathUtil(root->right, data, ans))
    {
        ans.push_back(root);
        return 1;
    }
    
    return 0;
}

vector<node*> nodetoRootPath(node *root, int data)
{
    vector<node*> ans;
    nodetoRootPathUtil(root, data, ans);
    return ans;
}

void printKlevelDown(node *root, int k, node *blocker)
{
    if(k < 0 || root == blocker)
        return;
    
    if(k == 0)
        cout<<root->data<<" ";
    
    printKlevelDown(root->left, k-1, blocker);
    printKlevelDown(root->right, k-1, blocker);
}

void KlevelFar(node *root, int data, int k)
{
    vector<node*> ans = nodetoRootPath(root, data);
    for(int i=0; i<ans.size(); i++)
    {
        printKlevelDown(ans[i], k-i, i==0?NULL:ans[i-1]);
    }
}


int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    node *root = constructTree(arr);
    KlevelFar(root, 37, 2);
}