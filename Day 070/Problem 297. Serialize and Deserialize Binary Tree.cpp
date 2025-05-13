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

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Split nodes into vector
        vector<string> nodes;
        stringstream ss(data);
        string node;
        while (getline(ss, node, ',')) {
            nodes.push_back(node);
        }

        int index = 0;
        return solve(nodes, index);
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
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));