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
    void preOrder(TreeNode *root, vector<long long> prevSumPaths, int target, int &answer) {
        if (!root) return;

        for (int i = 0; i < prevSumPaths.size(); i++) {
            prevSumPaths[i] += root->val;
            if (prevSumPaths[i] == target) answer++;
        }
        prevSumPaths.push_back(root->val);
        if (root->val == target) answer++;

        preOrder(root->left, prevSumPaths, target, answer);
        preOrder(root->right, prevSumPaths, target, answer);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int answer = 0;
        vector<long long> prevSumPaths;

        preOrder(root, prevSumPaths, targetSum, answer);
        return answer;
    }
};