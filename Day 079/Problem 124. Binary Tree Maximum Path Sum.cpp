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

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    map<TreeNode*, pair<int, int>> dp;
    int result = INT_MIN;
    pair<int, int> solve(TreeNode* root) {
        if (!root) return {0, 0}; 
        
        if (dp.find(root) != dp.end()) {
            return dp[root];
        }

        auto [singleLeftTree, combineLeftTree] = solve(root->left);
        auto [singleRightTree, combineRightTree] = solve(root->right);
        
        int singleRoot = max(root->val, root->val + max(singleLeftTree, singleRightTree));
        int combineRoot = max(root->val, singleLeftTree + root->val + singleRightTree);

        result = max(result, max(singleRoot, combineRoot));
        return {singleRoot, combineRoot};
    } 

    int maxPathSum(TreeNode* root) {
        auto [singleRoot, combineRoot] = solve(root);
        return result;
    }
};