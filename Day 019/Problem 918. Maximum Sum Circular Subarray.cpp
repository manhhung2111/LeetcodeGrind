class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Find the maximum suffix from index i onwards
        if (nums.size() == 1) return nums[0];
        
        int suffixSum = nums.back();
        vector<int> rightMax(nums.size(), nums.back());

        for (int i = nums.size() - 2; i >= 0; i--) {
            suffixSum += nums[i];
            rightMax[i] = max(rightMax[i+1], suffixSum);
        }

        int prefixSum = nums[0];
        int specialSum = nums[0] + rightMax[1];
        for (int i = 1; i < nums.size() - 1; i++) {
            prefixSum += nums[i];
            specialSum = max(specialSum, prefixSum + rightMax[i+1]);
        }

        // Find the normal sum of the array using Kadane's algorithm
        int sum = 0;
        int normalSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum = max(sum + nums[i], nums[i]);
            normalSum = max(normalSum, sum);
        }

        return max(normalSum, specialSum);
    }
};