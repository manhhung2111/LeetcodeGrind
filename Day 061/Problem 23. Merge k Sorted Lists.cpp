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
            while (list) {
                pq.push(list->val);
                list = list->next;
            }
        }

        ListNode *result = new ListNode();
        ListNode *ptr = result;

        while (!pq.empty()) {
            ptr->next =  new ListNode(pq.top()); pq.pop();
            ptr = ptr->next;
        }

        return result->next;
    }
};