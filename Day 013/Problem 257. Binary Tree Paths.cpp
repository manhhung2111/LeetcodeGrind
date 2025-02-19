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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};

        queue<pair<TreeNode*, string>> q;
        q.push({root, to_string(root->val)});

        vector<string> answer;
        while (!q.empty()) {
            pair<TreeNode*, string> nodePair = q.front(); q.pop();

            TreeNode* node = nodePair.first;
            string path = nodePair.second;

            if (node->left) q.push({node->left, path + "->" + to_string(node->left->val)});
            if (node->right) q.push({node->right, path + "->" + to_string(node->right->val)});

            if (!node->left && !node->right) {
                answer.push_back(path);
            }
        }

        return answer;
    }
};