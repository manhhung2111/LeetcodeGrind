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
    ListNode* reverseList(ListNode *head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        ListNode* list2 = reverseList(slow);
        ListNode* list1 = head;
        while (list1 && list2) {
            ListNode* next1 = list1->next;
            ListNode* next2 = list2->next;

            list1->next = list2;
            if(next1) list2->next = next1;

            list1 = next1; list2 = next2;
        }
    }
};