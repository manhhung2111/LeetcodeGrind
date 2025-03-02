/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodes;
    Solution(ListNode* head) {
        ListNode* ptr = head;

        while (ptr) {
            nodes.push_back(ptr->val);
            ptr = ptr->next;
        }
        srand(time(NULL));
    }
    
    int getRandom() {
        int idx = rand() % nodes.size();
        return nodes[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */