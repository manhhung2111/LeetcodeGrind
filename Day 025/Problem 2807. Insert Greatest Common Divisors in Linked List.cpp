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
    int gcd(int a, int b) {
        if (b != 0) return gcd(b, a % b);
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* curr = head, *next = head->next;
        while (next) {
            ListNode* node = new ListNode(gcd(curr->val, next->val));
            curr->next = node;
            node->next = next;
            curr = next;
            next = next->next;
        }

        return head;
    }
};