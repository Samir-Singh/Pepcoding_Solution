// Approach 1 : 
class Solution
{
    vector<int> arr;
    public:
    //Function to check whether a Binary Tree is BST or not.
    void inorder(Node *root)
    {
        if(!root)
            return;
        inorder(root->left);
        arr.push_back(root->data);
        inorder(root->right);
    }
    
    bool isBST(Node* root) 
    {
        if(!root)
            return true;
        inorder(root);
        
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i] <= arr[i-1])
                return false;
        }
        
        return true;
    }
};


// Approach 2 :
class Solution {
public:
    int maxValue(TreeNode *root)
    {
        if(root == NULL)
            return INT_MIN;
        return max(root->val, max(maxValue(root->left), maxValue(root->right)));
    }
    int minValue(TreeNode *root)
    {
        if(root == NULL)
            return INT_MAX;
        return min(root->val, min(minValue(root->left), minValue(root->right)));
    }
    
    
    
    bool isValidBST(TreeNode* node) {
    if (node == NULL)
        return true;
        
    if ((node->left && maxValue(node->left) >= node->val) || (node->right && minValue(node->right) <= node->val))
        return false;
        
    if (!isValidBST(node->left) || !isValidBST(node->right))
        return false;
        
    return true;
    }
};