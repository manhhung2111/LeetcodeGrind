/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    public:
    
        void flattenNode(Node* node, vector<Node*> &nodes) {
            queue<Node*> q;
            q.push(node);
    
            while (!q.empty()) {
                // Process current node
                Node* node = q.front(); q.pop();
    
                Node* newNode = new Node();
                newNode->val = node->val;
                nodes.push_back(newNode);
    
                // Process child nodes
                if (node->child) {
                    flattenNode(node->child, nodes);
                }
    
                if (node->next) {
                    q.push(node->next);
                }
            }
        }
    
        Node* flatten(Node* head) {
            if (!head) return head;
            
            vector<Node*> nodes;
    
            flattenNode(head, nodes);
    
            for (int i = 0; i < nodes.size() - 1; i++) {
                Node* cur = nodes[i];
                Node* next = nodes[i+1];
    
                cur->next = next;
                next->prev = cur;
            }
            
            return nodes[0];
        }
    };