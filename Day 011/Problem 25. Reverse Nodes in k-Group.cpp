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

    /**
    * Reverse list with length k from node 
    */
    vector<ListNode*> reverseListK(ListNode* node, int k) {
        ListNode *prev = node, *curr = node;

        while (curr && k) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k--;
        }

        return {prev, curr};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        ListNode *dummyPtr = dummy;
        
        // Find the length of the linked list
        int n = 0;
        ListNode *ptr = head;
        while (ptr) {
            ptr = ptr->next;
            n++;
        }

        // Start to reverse group size K 
        for (int i = k; i <= n && head; i += k) {
            vector<ListNode*> rList = reverseListK(head, k);
            dummyPtr->next = rList[0];
            dummyPtr = head;
            head = rList[1];
        }

        dummyPtr->next = head;

        return dummy->next;
    }
};