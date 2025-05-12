class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMin = 1, curMax = 1;
        int result = INT_MIN;

        for (int num : nums) {
            if (num < 0) {
                swap(curMin, curMax);
            }

            curMax = max(curMax * num, num);
            curMin = min(curMin * num, num);

            result = max(result, curMax);
        }

        return result;
    }
};