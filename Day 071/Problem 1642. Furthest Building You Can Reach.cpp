class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, decltype([](int &a, int &b) {
            return a > b;
        })> minHeap;

        for (int i = 0; i < n - 1; i++) {
            if (heights[i] < heights[i + 1]) {
                minHeap.push(heights[i + 1] - heights[i]);
                // Use bricks
                if (minHeap.size() > ladders) {
                    if (bricks >= minHeap.top()) {
                        bricks -= minHeap.top();
                        minHeap.pop();
                    } else {
                        return i;
                    }
                }
            }
        }

        return n - 1;
    }
};