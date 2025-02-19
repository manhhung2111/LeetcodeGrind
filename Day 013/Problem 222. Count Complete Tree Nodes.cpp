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

    void preOrder(TreeNode *root, int &answer) {
        if (!root) return;

        answer++;
        preOrder(root->left, answer);
        preOrder(root->right, answer);
    }

    int countNodes(TreeNode* root) {
        int answer = 0;
        preOrder(root, answer);

        return answer;
    }
};