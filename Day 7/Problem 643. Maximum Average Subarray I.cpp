class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = INT_MIN;
        int windowSum = 0;
        int windowStart = 0;

        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            windowSum += nums[windowEnd];
            
            if (windowEnd - windowStart + 1 == k) {
                maxSum = max(maxSum, windowSum);
                windowSum -= nums[windowStart];
                windowStart++;
            }
        }

        return (double) maxSum / k;
    }
};