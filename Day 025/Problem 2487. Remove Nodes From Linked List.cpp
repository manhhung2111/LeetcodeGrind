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
    ListNode* removeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        
        ListNode* ptr = head; 
        stack<ListNode*> stk;
        while (ptr) {
            while (!stk.empty() && ptr->val > stk.top()->val) {
                stk.pop();
            }
            stk.push(ptr);
            ptr = ptr->next;
        }

        ptr = dummy;
        while (!stk.empty()) {
            stk.top()->next = ptr->next;
            ptr->next = stk.top();
            stk.pop();
        }

        return dummy->next;
    }
};