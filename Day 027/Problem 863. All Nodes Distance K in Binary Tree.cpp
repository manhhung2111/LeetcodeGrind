/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) return {target->val};

        map<int, vector<int>> graph;
        // Build graph
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            if (node->left) {
                graph[node->val].push_back(node->left->val);
                graph[node->left->val].push_back(node->val);
                q.push(node->left);
            }

            if (node->right) {
                graph[node->val].push_back(node->right->val);
                graph[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }

        queue<int> que;
        que.push(target->val);
        map<int, bool> visited;
        visited[target->val] = true;

        while (k) {
            int n = que.size();
            k--;

            vector<int> neighbors;
            for (int i = 0; i < n; i++) {
                int node = que.front(); que.pop();
                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        neighbors.push_back(neighbor);
                        que.push(neighbor);
                    }
                }
            }

            if (k == 0) {
                return neighbors;
            }
        }

        return {};
    }
};