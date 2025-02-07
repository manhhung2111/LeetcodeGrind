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
    /**
    * - We assume that the distance from the head ò List A to the intersection is a. Similarly, b for the distance in list B
    * - If we somehow let the 2 pointers start at the same distance from the intersection. We can ensure that the 2 pointers meet at the intersection
    * - To achieve that point, we traverse the 2 pointers to the end of each list. When the first pointer reaches the end of the list
    *   it continues to traverse from the beginning of list B, and when the second pointer reaches the beginning of the list A. At that point
    *   the two pointers are in the same distance from the intersection
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *first = headA, *second = headB;

        while (first != second) {
            if (first == nullptr) {
                first = headB;
            } else {
                first = first->next;
            }

            if (second == nullptr) {
                second = headA;
            } else {
                second = second->next;
            }
        }

        return first;
    }
};