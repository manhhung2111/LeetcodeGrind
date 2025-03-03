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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr = head;
        int n = 0;

        while (ptr) {
            n++;
            ptr = ptr->next;
        }

        ListNode *ptr1 = nullptr, *ptr2 = nullptr;
        ptr = head;
        int count = 1;

        while (count < k) {
            ptr = ptr->next;
            count++;
        }

        ptr1 = ptr;

        count = 1;
        ptr = head;
        while (count < n - k + 1) {
            ptr = ptr->next;
            count++;
        }

        ptr2 = ptr;

        swap(ptr1->val, ptr2->val);
        return head;
    }
};