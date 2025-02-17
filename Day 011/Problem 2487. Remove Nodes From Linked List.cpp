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
        ListNode *prev = nullptr, *curr = head;
        
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    
    ListNode* removeNodes(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* rList = reverseList(head);
        int currMax = rList->val;

        ListNode* dummyNode = new ListNode(0); // Track the only valid nodes
        ListNode* ptr1 = rList; // Traverse the list
        ListNode* ptr2 = dummyNode;

        while (ptr1) {
            if (ptr1->val < currMax) ptr1 = ptr1->next;
            else {
                currMax = ptr1->val;
                ptr2->next = ptr1;
                ptr2 = ptr2->next;
                ptr1 = ptr1->next;
            }
        }
        ptr2->next = nullptr;

        return reverseList(dummyNode->next);
    }
};