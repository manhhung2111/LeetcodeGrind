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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return nullptr;

        TreeNode *root = new TreeNode(postorder.back());

        vector<int> inOrderLeftTree, inOrderRightTree;
        vector<int> postOrderLeftTree, postOrderRightTree;

        bool passingRootNode = false;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root->val) {
                passingRootNode = true;
                continue;
            }

            if (!passingRootNode) {
                inOrderLeftTree.push_back(inorder[i]);
            } else {
                inOrderRightTree.push_back(inorder[i]);
            }
        }

        for (int i = 0; i < postorder.size() - 1; i++) {
            if (postOrderLeftTree.size() != inOrderLeftTree.size()) {
                postOrderLeftTree.push_back(postorder[i]);
            } else {
                postOrderRightTree.push_back(postorder[i]);
            }
        }

        root->left = buildTree(inOrderLeftTree, postOrderLeftTree);
        root->right = buildTree(inOrderRightTree, postOrderRightTree);

        return root;
    }
};