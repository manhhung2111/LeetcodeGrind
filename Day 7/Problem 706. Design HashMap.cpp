class MyHashMap {
private:
    struct ListNode {
        int key;
        int val;
        ListNode *next;
        ListNode() : key(0), val(0), next(nullptr) {}
        ListNode(int key, int val): key(key), val(val), next(nullptr) {}
        ListNode(int key, int val, ListNode *next): key(key), val(val), next(next) {}
    };
public:
    vector<ListNode*> myMap;
    MyHashMap() {
        for (int i = 0; i < 10000; i++) {
            myMap.push_back(new ListNode());
        }
    }
    
    void put(int key, int value) {
        int index = key % myMap.size();

        ListNode *head = myMap[index];
        // Insert at tail of the linked list OR update value along the way traversing to tail

        ListNode *ptr = head;
        while (ptr->next) {
            if (ptr->next->key == key) {
                ptr->next->val = value;
                return;
            }
            ptr = ptr->next;
        }

        ptr->next = new ListNode(key, value);
    }
    
    int get(int key) {
        int index = key % myMap.size();

        ListNode *head = myMap[index];
        ListNode *ptr = head->next;

        while (ptr) {
            if (ptr->key == key) {
                return ptr->val;
            }
            ptr = ptr->next;
        }
        
        return -1;
    }
    
    void remove(int key) {
        int index = key % myMap.size();

        ListNode *head = myMap[index];
        ListNode *ptr = head;

        while (ptr->next) {
            if (ptr->next->key == key) {
                ptr->next = ptr->next->next;
                return;
            }
            ptr = ptr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */