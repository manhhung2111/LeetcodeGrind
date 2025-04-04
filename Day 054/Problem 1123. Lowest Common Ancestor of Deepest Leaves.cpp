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

    vector<TreeNode*> findDeepestLeaves(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent) {
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = root;

        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> currLevel;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                currLevel.push_back(node);

                if (node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }

                if (node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }

            if (q.empty()) {
                return currLevel;
            }
        }

        return {};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> parent;

        vector<TreeNode*> leaves = findDeepestLeaves(root, parent);

        if (leaves.size() == 1) {
            return leaves[0];
        }

        unordered_set<TreeNode*> ancestors(leaves.begin(), leaves.end());

        while (ancestors.size() != 1) {
            unordered_set<TreeNode*> nextAncestors; // Store the next level separately

            for (TreeNode* item : ancestors) {
                nextAncestors.insert(parent[item]); // Add the parent node
            }

            ancestors = nextAncestors;
        }

        return *ancestors.begin();
    }
};