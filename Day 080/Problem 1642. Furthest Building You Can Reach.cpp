class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<>> minHeap;

        for (int i = 0; i < heights.size() - 1; i++) {
            if (heights[i] >= heights[i + 1]) continue;
            else {
                minHeap.push(heights[i + 1] - heights[i]);
                if (minHeap.size() > ladders) {
                    int neededBricks = minHeap.top(); minHeap.pop();
                    bricks -= neededBricks;
                    if (bricks < 0) return i;
                }
            }
        }

        return heights.size() - 1;
    }
};