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
class BSTIterator {
public:
    vector<int> nodes;
    int ptr = 0;

    void inorderTraverse(TreeNode* root) {
        if (!root) return;

        inorderTraverse(root->left);
        nodes.push_back(root->val);
        inorderTraverse(root->right);
    }
    BSTIterator(TreeNode* root) {
        inorderTraverse(root);
    }
    
    int next() {
        ptr++;
        return nodes[ptr - 1];
    }
    
    bool hasNext() {
        return (ptr + 1 <= nodes.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */