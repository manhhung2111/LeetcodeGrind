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
        
        ListNode *sen = new ListNode(0, head);
        
        ListNode *ptr = sen, *slow = head, *fast = head->next;
        while(fast) {
            if (slow->val == fast->val) {
                while (fast && slow->val == fast->val) {
                    fast = fast->next;
                }

                slow = fast;
                if (fast) {
                    fast = fast->next;
                }
            } else {
                ptr->next = slow;
                ptr = ptr->next;
                slow = slow->next;
                fast = fast->next;
            }
        }
        ptr->next = slow;
        if (slow) slow->next = nullptr;

        return sen->next;
    }
};