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

    vector<int> nodes;
    void traverse(TreeNode* root) {
        if (!root) return;

        traverse(root->left);
        nodes.push_back(root->val);
        traverse(root->right);
    
    }

    int minDiffInBST(TreeNode* root) {
        traverse(root);

        int answer = INT_MAX;
        for (int i = 0; i < nodes.size() - 1; i++) {
            answer = min(answer, nodes[i+1] - nodes[i]);
        }

        return answer;
    }
};