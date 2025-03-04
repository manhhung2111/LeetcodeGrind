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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int, bool> deleted;
        for (int num : nums) {
            deleted[num] = true;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* ptr1 = head, *ptr2 = dummy;
        while (ptr1) {
            if (!deleted[ptr1->val]) {
                ptr2->next = ptr1;
                ptr2 = ptr2->next;
            } 

            ptr1 = ptr1->next;
        }

        ptr2->next = nullptr;

        return dummy->next;
    }
};