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
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;

        while (left && right) {
            if (left->val < right->val) {
                ptr->next = left;
                left = left->next;
            } else {
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }

        if (left) ptr->next = left;
        
        if (right) ptr->next = right;
        
        return dummy->next;
    }

    void mergeSort(ListNode *&head) {
        if (!head || !head->next) return;

        ListNode* slow = head, *fast = head, *supaSlow = nullptr;

        while (fast && fast->next) {
            supaSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        supaSlow->next = nullptr;
        mergeSort(head);
        mergeSort(slow);
        head = merge(head, slow);
    }
    
    ListNode* sortList(ListNode* head) {
        mergeSort(head);
        return head;
    }
};