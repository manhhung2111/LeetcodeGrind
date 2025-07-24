class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) {this.val = val;}
    ListNode(int val, ListNode next) {this.val = val; this.next = next;}
}

class Solution {
    private int getLength(ListNode head) {
        int result = 0;
        for (ListNode ptr = head; ptr != null; ptr = ptr.next) {
            result++;
        }

        return result;
    }

    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] parts = new ListNode[k];
        int totalLength = getLength(head);

        int baseSize = totalLength / k;          // Minimum number of nodes in each part
        int extraNodes = totalLength % k;        // Extra nodes to distribute one per part

        ListNode current = head;
        for (int i = 0; i < k && current != null; i++) {
            parts[i] = current;

            int currentPartSize = baseSize + (extraNodes-- > 0 ? 1 : 0);
            for (int j = 1; j < currentPartSize; j++) {
                current = current.next;
            }

            // Cut off the current part and move to the next
            ListNode next = current.next;
            current.next = null;
            current = next;
        }

        return parts;
    }
}