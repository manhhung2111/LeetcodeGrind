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
    unordered_map<int, vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if ((n & 1) == 0) {
            return {};
        }
        
        if (n == 1) {
            return {new TreeNode()}; 
        }

        if (dp.find(n) != dp.end()) {
            return dp[n];
        }

        vector<TreeNode*> result;
        for (int i = 1; i < n; i += 2) {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n - i - 1);

            for (TreeNode* leftTree : left) {
                for (TreeNode* rightTree : right) {
                    TreeNode* root = new TreeNode(0, leftTree, rightTree);
                    result.push_back(root);
                }
            }
        }

        return dp[n] = result;
    }
};

