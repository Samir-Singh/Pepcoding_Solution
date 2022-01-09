int ntrp(node *root, int x, vector<int> &ans)
{
    if(root == NULL)
        return 0;

    if(root->data == x)
    {
        ans.push_back(root->data);
        return 1;
    }

    if(x < root->data)
    {
        if(ntrp(root->left, x, ans))
        {
            ans.push_back(root->data);
            return 1;
        }
    }

    if(x > root->data)
    {
        if(ntrp(root->right, x, ans))
        {
            ans.push_back(root->data);
            return 1;
        }
    }

    return 0;
}

int lcaofBST(node *root, int a, int b)
{
    vector<int> arr1, arr2;
    ntrp(root, a, arr1);
    ntrp(root, b, arr2);

    int i = arr1.size();
    int j = arr2.size();
    while(i>=0 && j>=0 && arr1[i] == arr2[j])
    {
        i--;
        j--;
    }

    return arr1[i+1];
}


// TC : O(heightoftree)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;

        if(root == p || root == q)
            return root;

        if(p->val<root->val && q->val<root->val)
            return lowestCommonAncestor(root->left, p, q);

        if(p->val>root->val && q->val>root->val)
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};
