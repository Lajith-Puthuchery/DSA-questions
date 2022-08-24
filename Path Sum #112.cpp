/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool temp(TreeNode* root, int targetSum, int currSum)
    {
        if(root==NULL)
            return false;
        currSum+=root->val;
        if(root->right==NULL && root->left==NULL)
        {
            if(targetSum==currSum)
                return true;
            return false;
        }
        return ((temp(root->left, targetSum, currSum)) or (temp(root->right, targetSum, currSum)));
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        return temp(root, targetSum, 0);
    }
};