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
    int answer = 0;
    void inorderTraverse(TreeNode* root, int &count, int k) {
        if (!root) return;

        inorderTraverse(root->left, count, k);
        if (count == k) {
            answer = root->val;
        } 
        count++;
        inorderTraverse(root->right, count, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;

        int count = 1;
        inorderTraverse(root, count, k);
       
        return answer;
    }
};