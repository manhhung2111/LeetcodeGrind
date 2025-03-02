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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (ListNode* list : lists) {
            ListNode* ptr = list;
            while (ptr) {
                pq.push(ptr->val);
                ptr = ptr->next;
            }
        }

        ListNode *result = new ListNode();
        ListNode *ptr = result;

        while (!pq.empty()) {
            ListNode *node = new ListNode(pq.top()); pq.pop();
            ptr->next = node;
            ptr = ptr->next;
        }

        return result->next;
    }
};