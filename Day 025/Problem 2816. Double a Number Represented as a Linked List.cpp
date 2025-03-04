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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }


    ListNode* doubleIt(ListNode* head) {
        ListNode* l = reverseList(head);

        int carry = 0;
        ListNode* list = new ListNode(0);
        ListNode* ptr = list;
        while (l) {
            int result = l->val * 2 + carry;
            int val = result  % 10;
            carry = result / 10;

            ptr->next = new ListNode(val);
            ptr = ptr->next;
            l = l->next;
        }

        if (carry) ptr->next = new ListNode(carry);

        return reverseList(list->next);
    }
};