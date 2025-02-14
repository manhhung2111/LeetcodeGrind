/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            // A map that mapping the old node with brand new node
            map<Node*, Node*> newNodes;
    
            Node* ptr = head;
            while (ptr) {
                Node* node = nullptr;
                if (newNodes[ptr]) {
                    node = newNodes[ptr];
                } else {
                    node = new Node(ptr->val);
                    newNodes[ptr] = node;
                }
    
                if (ptr->next) {
                    Node* nextNode = nullptr;
                    if (newNodes[ptr->next]) {
                        nextNode = newNodes[ptr->next];
                    } else {
                        nextNode = new Node(ptr->next->val);
                        newNodes[ptr->next] = nextNode;
                    }
                    node->next = nextNode;
                }
    
                if (ptr->random) {
                    Node* randomeNode = nullptr;
                    if (newNodes[ptr->random]) {
                        randomeNode = newNodes[ptr->random];
                    } else {
                        randomeNode = new Node(ptr->random->val);
                        newNodes[ptr->random] = randomeNode;
                    }
                    node->random = randomeNode;
                }
    
                ptr = ptr->next;
            }
    
            return newNodes[head];
        }
    };