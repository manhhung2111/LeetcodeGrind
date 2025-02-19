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

    void preOrder(TreeNode *root, int curMax, int curMin, int &answer) {
        if (!root) return;

        answer = max(curMax - root->val, max(root->val - curMin, answer));
        curMax = max(curMax, root->val);
        curMin = min(curMin, root->val);

        preOrder(root->left, curMax, curMin, answer);
        preOrder(root->right, curMax, curMin, answer);
    }

    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;

        int answer = 0;
        int curMax = root->val;
        int curMin = root->val;
        preOrder(root, curMax, curMin, answer);

        return answer;
    }
};