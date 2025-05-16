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
    map<pair<TreeNode*, bool>, int> dp;
    int solve(TreeNode *&root, bool canBreak) {
        if (!root) return 0;

        if (dp.find({root, canBreak}) != dp.end()) {
            return dp[{root, canBreak}];
        }

        if (canBreak) {
            int take = root->val + solve(root->left, false) + solve(root->right, false);
            int skip = solve(root->left, true) + solve(root->right, true);
            return dp[{root, canBreak}] = max(take, skip);
        }

        return dp[{root, canBreak}] = solve(root->left, true) + solve(root->right, true);
    }

    int rob(TreeNode* root) {
        return solve(root, true);
    }
};