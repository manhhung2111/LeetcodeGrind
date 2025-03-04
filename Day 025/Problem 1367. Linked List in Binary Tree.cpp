/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool stringContains(string s, string t) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[0] && (i + t.size() - 1) < s.size()) {
                bool valid = true;
                for (int j = 0; j < t.size(); j++) {
                    if (s[i +j] != t[j]) {
                        valid = false;
                        break;
                    }
                }

                if (valid) return true;
            }
        }

        return false;
    }

    void traverse(TreeNode* root, bool &result, string list) {
        if (!root) return;

        queue<pair<TreeNode*, string>> q;
        q.push({root, to_string(root->val)});

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                pair<TreeNode*, string> entry = q.front(); q.pop();

                if (stringContains(entry.second, list)) result = true;
                if (entry.first->left) {
                    q.push({entry.first->left, entry.second + "," + to_string(entry.first->left->val)});
                } 

                if (entry.first->right) {
                    q.push({entry.first->right, entry.second + "," + to_string(entry.first->right->val)});
                }
            }

            if (result) break;
        }
    }

    void dfs(TreeNode* root, string path, string list, bool &result) {
        if (!root || result) return;

        string newPath = path + (path.size() > 0? "," : "") + to_string(root->val);
        if (stringContains(newPath, list)) result = true;

        dfs(root->left, newPath, list, result);
        dfs(root->right, newPath, list, result);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        string list = "";
        while (head) {
            if (list.size() > 0) list += ",";
            list += to_string(head->val);
            head = head->next;
        }

        bool result = false;
        traverse(root, result, list);
        // dfs(root, "", list, result);

        return result;
    }
};