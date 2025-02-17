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
    vector<ListNode*> reverseKGroup(ListNode *head, int k) {
        ListNode *prev = nullptr, *curr = head;

        while (curr && k) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k--;
        }

        return {prev, curr};
    }

    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* ptr = head;
        int n = 0;
        while (ptr) {
            ptr = ptr->next;
            n++;
        }

        ptr = head;
        ListNode* prevPtr = head;
        int groupSize = 1;
        
        while (ptr) {
            int size = (groupSize + 1) * groupSize / 2;
            // The remaining nodes fit the current group
            if (size < n) {
                if (groupSize % 2 == 0) {
                    vector<ListNode*> rList = reverseKGroup(ptr, groupSize);
                    prevPtr->next = rList[0];
                    prevPtr = ptr;
                    ptr->next = rList[1];
                    ptr = ptr->next;
                } else {
                    for (int i = 0; i < groupSize; i++) {
                        prevPtr = ptr;
                        ptr = ptr->next;
                    }
                }
            } else {
                // This is the last group, check if the remaining nodes divisible by 2
                int remainingNodes = groupSize - (size - n);
                if (remainingNodes % 2 == 0) {
                    vector<ListNode*> rList = reverseKGroup(ptr, remainingNodes);
                    prevPtr->next = rList[0];
                } else {
                    prevPtr->next = ptr;
                }
                break;
            }
            groupSize++;
        }

        return head;
    }
};