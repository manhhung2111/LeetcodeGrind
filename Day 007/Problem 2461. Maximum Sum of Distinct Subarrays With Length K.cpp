class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int, int> frequency;

        int windowStart = 0;
        long long windowSum = 0, maxSum = INT_MIN;

        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            frequency[nums[windowEnd]]++;
            windowSum += nums[windowEnd];

            if (frequency[nums[windowEnd]] > 1) {
                while (frequency[nums[windowEnd]] > 1) {
                    frequency[nums[windowStart]]--;
                    windowSum -= nums[windowStart];
                    windowStart++;
                }
            }

            if (windowEnd - windowStart + 1 == k) {
                maxSum = max(windowSum, maxSum);
                frequency[nums[windowStart]]--;
                windowSum -= nums[windowStart];
                windowStart++;
            }
        }

        return maxSum == INT_MIN ? 0 : maxSum;
    }
};