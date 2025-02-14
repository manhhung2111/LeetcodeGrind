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
        if (!head || !head->next) return head;

        ListNode *prev = nullptr, *current = head, *next = head->next;
        while (current) {
            current->next = prev;
            prev = current;
            current = next;
            if (next) next = next->next;
        }

        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Now the slow pointer is at the begin of the second half array
        ListNode* list1 = head;
        ListNode* list2 = reverseList(slow);

        int answer = INT_MIN;
        while (list1 && list2) {
            answer = max(list1->val + list2->val, answer);
            list1 = list1->next;
            list2 = list2->next;
        }

        return answer;
    }
};