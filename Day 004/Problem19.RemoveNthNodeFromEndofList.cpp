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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        
        // Let fast pointer steps ahead n steps first from slow pointer. 
        // When fast pointer reaches the end of the list. The slow pointer stops at the node before the deleted node
        int step = 0;
        while (step < n) {
            fast = fast->next;
            step++;
        }

        // The node needs to be delted is the first node
        if (!fast) {
            return head->next;
        }

        ListNode *slow = head;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};