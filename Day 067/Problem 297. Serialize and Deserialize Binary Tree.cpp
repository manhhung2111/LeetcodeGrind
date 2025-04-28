/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* solve(const vector<string> &nodes, int &index) {
        if (nodes[index] == "#") {
            index++;
            return nullptr;
        } 

        TreeNode* root = new TreeNode(stoi(nodes[index++]));
        root->left = solve(nodes, index);
        root->right = solve(nodes, index);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }

        int index = 0;
        return solve(nodes, index);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));