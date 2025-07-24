class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) {this.val = val;}
    ListNode(int val, ListNode next) {this.val = val; this.next = next;}
}

class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode sentinel = new ListNode();
        ListNode prevNode = sentinel, ptr = list1;
        int index = 0;

        while (index < a) {
            prevNode.next = ptr;
            prevNode = prevNode.next;
            ptr = ptr.next;
            index++;
        }

        while (index <= b) {
            ptr = ptr.next;
            index++;
        }

        prevNode.next = list2;
        while (prevNode.next != null) {
            prevNode = prevNode.next;
        }

        prevNode.next = ptr;
        return sentinel.next;
    }
}