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
        if (!head || !head->next) return nullptr;
        ListNode* fast = head;

        while (n && fast) {
            fast = fast->next;
            n--;
        }

        // The node need to be deleted is the head
        if (!fast) return head->next;

        // When the fast node reaches the last node, the slow pointer will point to the parent of deleted node
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};