class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) {this.val = val;}
    ListNode(int val, ListNode next) {this.val = val; this.next = next;}
}

class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode sentinel = new ListNode(0, head); // dummy node pointing to head
        ListNode current = sentinel;

        while (current.next != null) {
            if (current.next.val == val) {
                current.next = current.next.next; // skip the node
            } else {
                current = current.next; // move to next node
            }
        }

        return sentinel.next;
    }
}
