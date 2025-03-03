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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;

        int listLength = 0;
        ListNode* ptr = head;
        while (ptr) {
            listLength++;
            ptr = ptr->next;
        }

        int quotient = listLength / k;
        int remainder = listLength % k;

        ptr = head;
        ListNode* list = ptr;

        while (ptr) {
            int size = quotient;
            if (remainder > 0) {
                size++;
                remainder--;
            }

            for (int i = 0; i < size - 1; i++) {
                ptr = ptr->next;
            }

            ListNode* next = ptr->next;
            ptr->next = nullptr;
            ptr = next; 

            result.push_back(list);
            list = ptr;
        } 

        while (result.size() < k) {
            result.push_back(nullptr);
        }

        return result;
    }
};