class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // If the curSum is negative, there is no point of adding the previous subarray. 
            // Start a fresh subarray instead
            curSum = max(curSum + nums[i], nums[i]);
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};