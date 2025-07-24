class DListNode {
    int val;
    DListNode prev;
    DListNode next;
    DListNode() {};
    DListNode(int val) {this.val = val;}
    DListNode(int val, DListNode prev, DListNode next) {this.val = val; this.prev = prev; this.next = next;}
}

class MyLinkedList {
    DListNode head, tail;
    int size;
    public MyLinkedList() {
        this.head = new DListNode();
        this.tail = new DListNode();

        head.next = tail;
        tail.prev = head;
        size = 0;
    }
    
    public int get(int index) {
        if (index < 0 || index >= size) return -1;
        DListNode node = head;
        while (index >= 0) {
            node = node.next;
            index--;
        }

        return node.val;
    }
    
    public void addAtHead(int val) {
        DListNode node = new DListNode(val);
        
        node.next = head.next;
        node.prev = head;

        head.next.prev = node;
        head.next = node;
        size++;
    }
    
    public void addAtTail(int val) {
        DListNode node = new DListNode(val);
        
        node.next = tail;
        node.prev = tail.prev;

        tail.prev.next = node;
        tail.prev = node;
        size++;
    }
    
    public void addAtIndex(int index, int val) {
        if (index > size) return;

        if (index == 0) {
            this.addAtHead(val);
        } else if (index == size) {
            this.addAtTail(val);
        } else {
            DListNode ptr = head;
            while (index > 0) {
                ptr = ptr.next;
                index--;
            }

            DListNode nextNode = ptr.next;

            DListNode newNode = new DListNode(val);
            ptr.next = newNode;
            newNode.prev = ptr;

            newNode.next = nextNode;
            nextNode.prev = newNode;
            size++;
        }
        
    }
    
    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            DListNode nextNode = this.head.next.next;
            this.head.next = nextNode;
            nextNode.prev = this.head;
        } else if (index == size - 1) {
            DListNode prevNode = this.tail.prev.prev;
            this.tail.prev = prevNode;
            prevNode.next = this.tail;
        } else {
            DListNode ptr = head;
            while (index > 0) {
                ptr = ptr.next;
                index--;
            }

            DListNode nextNode = ptr.next.next;

            ptr.next = nextNode;
            nextNode.prev = ptr;
        }

        size--;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */