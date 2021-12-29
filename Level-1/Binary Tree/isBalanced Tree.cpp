// Approach 1
int height(node *root)
{
    if(root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int isBalanced(node *root)
{
    if(root == NULL || (!root->left && !root->right))
        return 1;
        
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(abs(lh-rh) > 1 || isBalanced(root->left) == 0 || isBalanced(root->right) == 0 )
        return 0;
    
    return 1;
}



// Approach 2
class myPair
{
public:
    int h;
    int isbal;
};

class Solution {
public:
    myPair isBalUtil(TreeNode *root)
    {
        if(root == NULL)
        {
            myPair ans;
            ans.h = 0;
            ans.isbal = 1;
            return ans;
        }
        
        myPair lp = isBalUtil(root->left);
        myPair rp = isBalUtil(root->right);
        
        myPair ans;
        ans.h = 1+max(lp.h, rp.h);
        ans.isbal = (abs(lp.h-rp.h) <= 1) && lp.isbal && rp.isbal;
        
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        myPair ans = isBalUtil(root);
        return ans.isbal;
    }
};