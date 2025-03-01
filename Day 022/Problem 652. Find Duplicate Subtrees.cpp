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
    map<TreeNode*, string> mp;
    map<string, int> freq; 

    string serialize(TreeNode* root, vector<TreeNode*> &answer) {
        if (!root) return "#";

        string left = "";
        if (root->left && mp.find(root->left) != mp.end()) {
            left = mp[root->left];
        } else {
            left = serialize(root->left, answer);
        }

        string right = "";
        if (root->right && mp.find(root->right) != mp.end()) {
            right = mp[root->right];
        } else {
            right = serialize(root->right, answer);
        }

        string result = to_string(root->val) + "_" + left + "_" + right;
        mp[root] = result;
        freq[result]++;

        if (freq[result] == 2) {
            answer.push_back(root);
        }

        return result;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        serialize(root, result);

        return result;
    }
};