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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int, int> mp = {{0, 1}}; 
        int sum = 0;

        deque<pair<int, int>> dq; // {value, prefixSum}
        dq.push_back({0, 0});

        ListNode *ptr = head;
        
        while (ptr) {
            sum += ptr->val;
            mp[sum]++;

            if (mp[sum] > 1) {
                while (!dq.empty() && dq.back().second != sum) {
                    mp[dq.back().second]--;
                    dq.pop_back();
                }
                mp[sum] = 1;
            } else {
                dq.push_back({ptr->val, sum});
            }

            ptr = ptr->next;
        }

        ListNode *dummy = new ListNode(0); dq.pop_front(); // Pop the first number
        ptr = dummy;
        while (!dq.empty()) {
            ListNode *node = new ListNode(dq.front().first); dq.pop_front();
            ptr->next = node;
            ptr = ptr->next;
        }

        return dummy->next;
    }
};