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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        vector<int> left, right;
        for (int i = 0; i < nums.size(); i++) {
            if (i < maxIndex) {
                left.push_back(nums[i]);
            } else if (i > maxIndex) {
                right.push_back(nums[i]);
            }
        }

        TreeNode* root = new TreeNode(nums[maxIndex]);
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);

        return root;
    }
};