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
    TreeNode* temp(TreeNode* root, vector<int>& nums, int low, int high)
    {
        if(low>high)
            return NULL;
        int mid=low+(high-low)/2;
        root = new TreeNode(nums[mid]);
        root->right=temp(root->right, nums, mid+1, high);
        root->left=temp(root->left, nums, low, mid-1);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return temp(NULL, nums, 0, nums.size()-1);
    }
};