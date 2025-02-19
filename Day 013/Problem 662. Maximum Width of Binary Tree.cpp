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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});

        int answer = 1;
        while (!q.empty()) {
            int n = q.size();

            unsigned long long left = -1, right = -1;
            for (int i = 0; i < n; i++) {
                pair<TreeNode*, unsigned long long> node = q.front(); q.pop();

                if (i == 0) left = node.second;
                if (i == n - 1) right = node.second;

                if (node.first->left) q.push({node.first->left, 2 * node.second});
                if (node.first->right) q.push({node.first->right, 2 * node.second + 1});
            }

            if (n > 1) {
                int distance = right - left + 1;
                answer = max(answer, distance);
            }
        }

        return (int)answer;
    }
};