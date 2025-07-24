class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) {this.val = val;}
    ListNode(int val, ListNode next) {this.val = val; this.next = next;}
}


class Solution {

    private ListNode reverseList(ListNode head) {
        ListNode prev = null, curr = head;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }


    public ListNode removeNodes(ListNode head) {
        ListNode rList = reverseList(head);
        int max = 0;

        ListNode sentinel = new ListNode();
        ListNode ptr = sentinel;

        while (rList != null) {
            max = Math.max(max, rList.val);
            if (rList.val >= max) {
                ptr.next = new ListNode(rList.val);
                ptr = ptr.next;
            }

            rList = rList.next;
        }

        return reverseList(sentinel.next);
    }
}