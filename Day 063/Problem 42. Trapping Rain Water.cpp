class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxLeft(height.size(), height.front());
        vector<int> maxRight(height.size(), height.back());

        for (int i = 1; i < height.size(); i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
            maxRight[height.size() - 1 - i] = max(maxRight[height.size() - i], height[height.size() - 1 - i]);
        }

        int result = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            int water = min(maxLeft[i - 1], maxRight[i + 1]) - height[i];
            result += (water >= 0 ? water : 0);
        }

        return result;
    }
};