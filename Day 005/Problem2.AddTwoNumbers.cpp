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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* answer = new ListNode(0);
            ListNode* ptr = answer;
    
            int carry = 0;
            while (l1 && l2) {
                int sum = l1->val + l2->val + carry;
                int quotient = sum % 10;
                carry = sum / 10;
    
                ListNode* node = new ListNode(quotient);
                ptr->next = node;
    
                ptr = ptr->next;
                l1 = l1->next;
                l2 = l2->next;
            }
    
            while (l1) {
                int sum = l1->val + carry;
                int quotient = sum % 10;
                carry = sum / 10;
    
                ListNode* node = new ListNode(quotient);
                ptr->next = node;
    
                ptr = ptr->next;
                l1 = l1->next;
            }
    
            while (l2) {
                int sum = l2->val + carry;
                int quotient = sum % 10;
                carry = sum / 10;
    
                ListNode* node = new ListNode(quotient);
                ptr->next = node;
    
                ptr = ptr->next;
                l2 = l2->next;
            }
    
            if (carry) {
                ListNode* node = new ListNode(1);
                ptr->next = node;
            }
    
            return answer->next;
        }
    };