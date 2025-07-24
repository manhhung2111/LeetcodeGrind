class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) {this.val = val;}
    ListNode(int val, ListNode next) {this.val = val; this.next = next;}
}

class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode ptr1 = headA, ptr2 = headB;

        while (ptr1 != ptr2) {
            if (ptr1 == null) {
                ptr1 = headB;
            } else {
                ptr1 = ptr1.next;
            }

            if (ptr2 == null) {
                ptr2 = headB;
            } else {
                ptr2 = ptr2.next;
            }
        }

        return ptr1;
    }
}
