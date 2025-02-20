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
    int findHeight(TreeNode* root) {
        if(!root) return -1;
        return max(findHeight(root->left), findHeight(root->right)) + 1;
    }

    int maxDiameter = 0;
    // single depth of 1 side, combined path
    void traverse(TreeNode* root, map<TreeNode*, pair<int, int>> &mp) {
        if(!root) return;
        traverse(root->left, mp);
        traverse(root->right, mp);
        int leftDepth = findHeight(root->left) + 1;
        int rightDepth = findHeight(root->right) + 1;
        mp[root] = {max(leftDepth, rightDepth), leftDepth + rightDepth};
        maxDiameter = max(maxDiameter, max(max(leftDepth, rightDepth), leftDepth + rightDepth));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        map<TreeNode*, pair<int, int>> mp;
        traverse(root, mp);

        return maxDiameter;
    }
};