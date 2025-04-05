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
    unordered_map<string, TreeNode*> mp;
    set<string> result;
    string solve(TreeNode* root) {
        if (!root) return "#";

        string leftTree = solve(root->left);
        string rightTree = solve(root->right);

        string serialized = leftTree + "," + rightTree + "," + to_string(root->val);
        if (mp.find(serialized) != mp.end()) {
            result.insert(serialized);
        }

        mp[serialized] = root;
        return serialized;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        if (result.size() == 0) return {};
        vector<string> temp (result.begin(), result.end());

        vector<TreeNode*> answer;
        for (string serialized : temp) {
            answer.push_back(mp[serialized]);
        }

        return answer;
    }
};