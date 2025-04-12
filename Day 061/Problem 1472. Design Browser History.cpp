class BrowserHistory {
private:
    struct ListNode {
        string url;
        ListNode* next;
        ListNode* prev;

        ListNode(): url(""), next(nullptr), prev(nullptr) {}
        ListNode(string str): url(str), next(nullptr), prev(nullptr) {}
        ListNode(string str, ListNode* prevPtr, ListNode* nextPtr): url(str), next(nextPtr), prev(prevPtr) {}
    };
public:
    ListNode* history = nullptr;

    BrowserHistory(string homepage) {
        history = new ListNode(homepage);
    }
    
    void visit(string url) {
        ListNode* newPage = new ListNode(url);
        history->next = newPage;
        newPage->prev = history;

        history = newPage;
    }
    
    string back(int steps) {
        while (history && history->prev && steps) {
            history = history->prev;
            steps--;
        }

        return history->url;
    }
    
    string forward(int steps) {
        while (history && history->next && steps) {
            history = history->next;
            steps--;
        }

        return history->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */