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
    map<TreeNode*, pair<int, int>> mp;
    int answer = INT_MIN;

    void traverse(TreeNode* root) {
        if (!root) return;

        traverse(root->left);
        traverse(root->right);

        pair<int, int> leftTree = root->left ? mp[root->left] : make_pair(0, 0);
        pair<int, int> rightTree = root->right ? mp[root->right] : make_pair(0, 0);

        int maxSingleSide = max(max(leftTree.first, rightTree.first) + root->val, root->val);
        int maxCombineSides = leftTree.first + root->val + rightTree.first;

        answer = max(answer, max(maxSingleSide, maxCombineSides));
        mp[root] = {maxSingleSide, maxCombineSides}; 
    }

    int maxPathSum(TreeNode* root) {
        traverse(root);
        return answer;
    }
};