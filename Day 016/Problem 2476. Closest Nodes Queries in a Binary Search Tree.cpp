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
    vector<int> nums;

    int getClosestValue(int target, bool findSmaller) {
        int start = 0, end = nums.size()-1;
        int answer = -1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(findSmaller) {
                (nums[mid] <= target) 
                ? answer = nums[mid], start = mid + 1
                : end = mid - 1;
            } else {
                (nums[mid] >= target)
                ? answer = nums[mid], end = mid - 1
                : start = mid + 1;
            }
        }

        return answer;
    }

    void inorderTraverse(TreeNode* root) {
        if (!root) return;

        inorderTraverse(root->left);
        nums.push_back(root->val);
        inorderTraverse(root->right);
    }


    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> answer;
        inorderTraverse(root);

        for (int num : queries) {
            int minElement = getClosestValue(num, true);
            int maxElement = getClosestValue(num, false);
            answer.push_back({minElement, maxElement}); 
        }

        return answer;
    }
};