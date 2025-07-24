class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) {this.val = val;}
    ListNode(int val, ListNode next) {this.val = val; this.next = next;}
}

class Solution {
    private ListNode rotate(ListNode head) {
        ListNode ptr = head;
        while (ptr.next.next != null) {
            ptr = ptr.next;
        }

        ListNode tail = ptr.next;
        ptr.next = null;

        tail.next = head;
        return tail;
    }

    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) return head;

        int size = 0;
        for (ListNode ptr = head; ptr != null; ptr = ptr.next) {
            size++;
        }

        k = k % size;

        for (int i = 0; i < k; i++) {
            head = rotate(head);
        }

        return head;
    }
}