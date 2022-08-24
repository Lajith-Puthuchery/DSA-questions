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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL)
            return NULL;
        TreeNode* rootmerge;
        if(root1!=NULL && root2==NULL)
        {
            rootmerge = new TreeNode(root1->val);
            rootmerge->right = mergeTrees(root1->right, NULL);
            rootmerge->left = mergeTrees(root1->left, NULL);
        }
        else if(root1==NULL && root2!=NULL)
        {
            rootmerge = new TreeNode(root2->val);
            rootmerge->right = mergeTrees(NULL, root2->right);
            rootmerge->left = mergeTrees(NULL, root2->left);
        }
        else
        {
            rootmerge = new TreeNode(root1->val+root2->val);
            rootmerge->right = mergeTrees(root1->right, root2->right);
            rootmerge->left = mergeTrees(root1->left, root2->left);
        }
        return rootmerge;
    }
};