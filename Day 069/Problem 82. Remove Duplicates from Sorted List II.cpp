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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(-1);
        ListNode* dummyPtr = dummy;
        ListNode* slow = head, *fast = head->next;

        while (fast) {
            if (slow->val != fast->val) {
                dummyPtr->next = slow;
                dummyPtr = dummyPtr->next;

                slow = slow->next;
                fast = fast->next;
            } else {
                while (fast && slow->val == fast->val) {
                    fast = fast->next;
                }
                slow = fast;
                if (fast) fast = fast->next;
            }
        }

        dummyPtr->next = slow;

        return dummy->next;
    }
};