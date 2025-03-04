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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr = list1, *list1Prev = nullptr, *list1Next = nullptr;

        int count = 0;
        while (count < a - 1 && ptr) {
            ptr = ptr->next;
            count++;
        }
        list1Prev = ptr;

        while (count < b && ptr) {
            ptr = ptr->next;
            count++;
        }
        if (ptr) list1Next = ptr->next;

        // Find the last node of list2
        ListNode* list2Last = nullptr;
        ptr = list2;

        while (ptr && ptr->next) {
            ptr = ptr->next;
        }

        list2Last = ptr;

        list1Prev->next = list2;
        list2Last->next = list1Next;

        return list1;
    }
};