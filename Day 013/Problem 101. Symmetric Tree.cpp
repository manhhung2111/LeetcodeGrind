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
    void invertTree(TreeNode *&root) {
        if (!root) return;

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        // swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;

        if (!p || !q) return false;

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        if (!root->left && !root->right) return true;
        
        invertTree(root->right);

        return isSameTree(root->left, root->right);
    }
};