class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> pq;
    int size = 1;
    KthLargest(int k, vector<int>& nums) {
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        size = k;
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > size) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */