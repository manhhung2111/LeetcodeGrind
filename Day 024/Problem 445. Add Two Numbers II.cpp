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
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list1 = reverseList(l1);
        ListNode* list2 = reverseList(l2);

        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        while (list1 && list2) {
            int sum = list1->val + list2->val + carry;
            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;
            carry = sum / 10;

            list1 = list1->next;
            list2 = list2->next;
        }

        while (list1) {
            int sum = list1->val + carry;
            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;
            carry = sum / 10;

            list1 = list1->next;
        }

        while (list2) {
            int sum = list2->val + carry;
            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;
            carry = sum / 10;
            
            list2 = list2->next;
        }

        if (carry) ptr->next = new ListNode(carry);

        return reverseList(dummy->next); 
    }
};