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
        ListNode* rotateRight(ListNode* head, int k) {
            if (!head || !head->next) return head;
            
            int listSize = 0;
            ListNode* temp = head;
            while (temp) {
                listSize++;
                temp = temp->next;
            }
    
            k = k % listSize;
    
            for (int i = 0; i < k; i++) {
                int prevVal = head->val;
    
                ListNode* ptr = head;
                while (ptr && ptr->next) {
                    int nextVal = ptr->next->val;
                    ptr->next->val = prevVal;
                    prevVal = nextVal;
                    ptr = ptr->next;
                }
    
                head->val = prevVal;
            }
            return head;
        }
    };