/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        map<int, Node*> mp;
        map<int, bool> visited;
        Node* root = new Node(node->val);
        mp[node->val] = root;

        queue<Node*> q;
        q.push(node);
        visited[node->val] = true;

        while (!q.empty()) {
            Node* curr = q.front(); q.pop();

            vector<Node*> neighbors;
            for (Node* neighbor : curr->neighbors) {
                Node* temp = nullptr;
                if (mp.find(neighbor->val) == mp.end()) {
                    temp = new Node(neighbor->val);
                    mp[neighbor->val] = temp;
                }
                temp = mp[neighbor->val];

                neighbors.push_back(temp);
                if (!visited[neighbor->val]) {
                    q.push(neighbor);
                    visited[neighbor->val] = true;
                }
            }

            mp[curr->val]->neighbors = neighbors;
        }

        return root;
    }
};