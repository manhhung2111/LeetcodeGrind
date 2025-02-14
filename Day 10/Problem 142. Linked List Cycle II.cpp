/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, bool> visited;

        ListNode *ptr = head;
        visited[ptr] = true;
        while (ptr) {
            ptr = ptr->next;
            if (ptr && visited[ptr]) {
                return ptr;
            }
            if (ptr) visited[ptr] = true;
        }

        return nullptr;
    }
};