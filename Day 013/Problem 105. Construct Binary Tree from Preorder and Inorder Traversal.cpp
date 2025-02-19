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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);

        vector<int> inOrderLeftTree, inOrderRightTree;
        vector<int> preOrderLeftTree, preOrderRightTree;

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

        for (int i = 1; i < preorder.size(); i++) {
            if (preOrderLeftTree.size() != inOrderLeftTree.size()) {
                preOrderLeftTree.push_back(preorder[i]);
            } else {
                preOrderRightTree.push_back(preorder[i]);
            }
        }

        root->left = buildTree(preOrderLeftTree, inOrderLeftTree);
        root->right = buildTree(preOrderRightTree, inOrderRightTree);

        return root;
    }
};