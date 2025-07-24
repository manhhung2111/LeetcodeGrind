class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) {this.val = val;}
    ListNode(int val, ListNode next) {this.val = val; this.next = next;}
}

class Solution {

    private ListNode merge(ListNode left, ListNode right) {
        ListNode sentinel = new ListNode();
        ListNode ptr = sentinel;

        while (left != null && right != null) {
            if (left.val < right.val) {
                ptr.next = new ListNode(left.val);
                left = left.next;
            } else {
                ptr.next = new ListNode(right.val);
                right = right.next;
            }

            ptr = ptr.next;
        }

        if (left != null) ptr.next = left;
        if (right != null) ptr.next = right;

        return sentinel.next;
    }

    private ListNode mergeSort(ListNode head) {
        if (head == null || head.next == null) return head;

        // Find middle node
        ListNode prev = null, slow = head, fast = head;
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        prev.next = null;
        ListNode left = mergeSort(head);
        ListNode right = mergeSort(slow);

        return merge(left, right);
    }

    public ListNode sortList(ListNode head) {
        return mergeSort(head);
    }
}