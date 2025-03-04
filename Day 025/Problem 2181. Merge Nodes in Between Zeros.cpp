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
    ListNode* mergeNodes(ListNode* head) {
        int countZeroNodes = 0;

        int sum = 0; 
        ListNode* ptr = head;
        ListNode* dummy = new ListNode(0);
        ListNode* ptr2 = dummy;

        while (ptr) {
            if (ptr->val == 0) countZeroNodes++;
            sum += ptr->val;
            
            if (countZeroNodes == 2) {
                ptr2->next = new ListNode(sum);
                sum = 0;
                ptr2 = ptr2->next;
                countZeroNodes = 1;
            }

            ptr = ptr->next;
        }

        return dummy->next;
    }
};