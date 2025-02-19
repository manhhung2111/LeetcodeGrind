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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;

        TreeNode* root = new TreeNode(nums[nums.size() / 2]);

        vector<int> leftTree;
        for (int i = 0; i < nums.size() / 2; i++) {
            leftTree.push_back(nums[i]);
        }

        vector<int> rightTree;
        for (int i = nums.size() / 2 + 1; i < nums.size(); i++) {
            rightTree.push_back(nums[i]);
        }
        
        root->left = sortedArrayToBST(leftTree);
        root->right = sortedArrayToBST(rightTree);

        return root;
    }
};