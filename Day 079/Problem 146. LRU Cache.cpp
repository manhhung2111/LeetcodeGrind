#include <bits/stdc++.h>

using namespace std;

struct DListNode {
    int key;
    int value;
    DListNode *next;
    DListNode *prev;

    DListNode(): key(-1), value(-1), next(nullptr), prev(nullptr) {};
    DListNode(int _key, int _val): key(_key), value(_val), next(nullptr), prev(nullptr) {};
};

class LRUCache {
private:
    DListNode *head = new DListNode(), *tail = new DListNode();
    int capacity;
    unordered_map<int, DListNode*> cache;

    void removeNode(DListNode *node) {
        DListNode *prev = node->prev, *next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insertNode(DListNode *node) {
        DListNode *next = head->next;
        head->next = node;
        node->next = next;
        
        node->prev = head;
        next->prev = node;
    }

    void removeTail() {
        DListNode *tailPrev = tail->prev;
        removeNode(tailPrev);
        cache.erase(tailPrev->key);
    }

    void printList() {
        DListNode* ptr = head;
        while (ptr->next) {
            cout << "(" << ptr->key << ", " << ptr->value << ") ";
            ptr = ptr->next;
        }
        cout << endl;
    }

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        DListNode* node = cache[key];
        removeNode(node);
        insertNode(node);

        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->value = value;
            removeNode(cache[key]);
            insertNode(cache[key]);
        } else {
            DListNode* node = new DListNode(key, value);
            cache[key] = node;

            if (cache.size() > capacity) {
                removeTail();
            }
            insertNode(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */