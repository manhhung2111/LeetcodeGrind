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
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> indexes;
        ListNode *prev = nullptr, *curr = head;

        int minDist = INT_MAX;
        int count = 1;
        while (curr) {
            if (prev && curr->next) {
                if (curr->val > prev->val && curr->val > curr->next->val) {
                    if (indexes.size() > 0) minDist = min(minDist, count - indexes.back());
                    indexes.push_back(count);
                } else if (curr->val < prev->val && curr->val < curr->next->val) {
                    if (indexes.size() > 0) minDist = min(minDist, count - indexes.back());
                    indexes.push_back(count);
                }
            }
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (indexes.size() < 2) return {-1, -1};

        return {minDist, indexes.back() - indexes[0]};
    }
};