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
    int listSize(ListNode* head) {
        int n = 0;
        ListNode *ptr = head;
        while (ptr) {
            n++;
            ptr = ptr->next;
        }

        return n;
    }

    pair<ListNode*, ListNode*> reverseKList(ListNode* head, int k) {
        ListNode* prev = nullptr, *current = head;

        while (current && k--) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return {prev, current};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = listSize(head);

        ListNode* ptr = head;
        ListNode* prev = nullptr;
        for (int i = 0; i <= n - k; i += k) {
            auto [reversedHead, nextNode] = reverseKList(ptr, k);
            if (i == 0) {
                head = reversedHead;
            }

            if (prev) {
                prev->next = reversedHead;
            }

            ptr->next = nextNode;
            prev = ptr;
            ptr = ptr->next;
        }

        return head;
    }
};