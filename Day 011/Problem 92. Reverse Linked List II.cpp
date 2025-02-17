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
    vector<ListNode*> reverseGroupList(ListNode* node, int count) {
        ListNode *prev = nullptr, *curr = node;

        while (curr && count) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count--;
        }

        return {prev, curr};
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode *dummy = new ListNode(0);

        ListNode *dummyPtr = dummy;
        ListNode* ptr = head;

        int count = 1;
        while (count < left && ptr) {
            dummyPtr->next = ptr;
            dummyPtr = dummyPtr->next;
            ptr = ptr->next;
            count++;
        }

        vector<ListNode*> rList = reverseGroupList(ptr, right - left + 1);
        dummyPtr->next = rList[0];
        ListNode* tailRList = rList[1]; 
        if (ptr) ptr->next = tailRList;

        return dummy->next;
    }
};