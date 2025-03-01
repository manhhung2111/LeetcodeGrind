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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        map<int, bool> shouldDelete;

        for (int node : to_delete) {
            shouldDelete[node] = true;
        }

        helper(root, shouldDelete, result, false);

        return result;
    }

    TreeNode* helper(TreeNode* root, map<int, bool> shouldDelete, vector<TreeNode*> &result, bool included) {
        if (!root) return nullptr;

        if (shouldDelete[root->val] == false) {
            if (!included) result.push_back(root);
            root->left = helper(root->left, shouldDelete, result, true);
            root->right = helper(root->right, shouldDelete, result, true);
            return root;
        }

        helper(root->left, shouldDelete, result, false);
        helper(root->right, shouldDelete, result, false);

        return nullptr;
    }
};