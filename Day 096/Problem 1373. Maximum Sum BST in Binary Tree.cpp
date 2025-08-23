#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    int result = INT_MIN;
    vector<int> postOrdertraverse(TreeNode* root) {
        if (!root) return {INT_MAX, INT_MIN, 0};

        vector<int> left = postOrdertraverse(root->left);
        vector<int> right = postOrdertraverse(root->right);

        if (!(left.size() != 0 && right.size() != 0 && root->val > left[1] && root->val < right[0])) {
            return {};
        }

        int sum = root->val + left[2] + right[2];
        result = max(result, sum);

        int minVal = min(root->val, left[0]);
        int maxVal = max(root->val, right[1]);

        return {minVal, maxVal, sum};
    }


    int maxSumBST(TreeNode* root) {
        postOrdertraverse(root);
        return result;
    }
};