class DoublyListNode {
    String val;
    DoublyListNode prev;
    DoublyListNode next;
    DoublyListNode() {}
    DoublyListNode(String val) {this.val = val;}
    DoublyListNode(String val, DoublyListNode prev, DoublyListNode next) {this.val = val; this.prev = prev; this.next = next;}
}

class BrowserHistory {
    DoublyListNode node;
    public BrowserHistory(String homepage) {
        node = new DoublyListNode(homepage);
    }
    
    public void visit(String url) {
        DoublyListNode newNode = new DoublyListNode(url);
        newNode.prev = node;
        node.next = newNode;

        node = node.next;
    }
    
    public String back(int steps) {
        while (steps > 0 && node.prev != null) {
            node = node.prev;
            steps--;
        }

        return node.val;
    }
    
    public String forward(int steps) {
        while (steps > 0 && node.next != null) {
            node = node.next;
            steps--;
        }

        return node.val;
    }
}