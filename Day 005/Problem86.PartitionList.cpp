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
        ListNode* partition(ListNode* head, int x) {
            if (!head || !head->next) return head;
            
            vector<int> smallerList, greaterList;
    
            ListNode* ptr = head;
            while (ptr) {
                if (ptr->val < x) {
                    smallerList.push_back(ptr->val);
                } else {
                    greaterList.push_back(ptr->val);
                }
                ptr = ptr->next;
            }
    
            ListNode* newHead = new ListNode();
            ptr = newHead;
    
            for (int num : smallerList) {
                ListNode* node = new ListNode(num);
                ptr->next = node;
                ptr = ptr->next;
            }
    
    
            for (int num : greaterList) {
                ListNode* node = new ListNode(num);
                ptr->next = node;
                ptr = ptr->next;
            }
    
            return newHead->next;
        }
    };