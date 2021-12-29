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
    stack<pair<node*, int>> st;
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
                pair<node*,int> lp = {newNode,1};
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
                pair<node*,int> rp = {newNode,1};
                st.push(rp);
            }
            idx++;
        }
        else
            st.pop();
    }
    
    return root;
}

vector<int> ans;
int find(node *root, int k)
{
    if(root == NULL)
        return 0;
        
    if(root->data == k)
    {
        ans.push_back(root->data);
        return 1;
    }
    
    if(find(root->left, k)|| find(root->right, k))
    {
        ans.push_back(root->data);
        return 1;
    }
    
    return 0;
}

vector<int> nodeToRootPath(node *root, int k)
{
    find(root, k);
}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    node *root = constructTree(arr);
    if(find(root, 30))
        cout<<"true";
    else
        cout<<"false";
    vector<int> ans = nodeToRootPath(root, 30);
    cout << "[";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i != ans.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}