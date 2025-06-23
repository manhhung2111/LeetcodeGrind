class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        int left = 0, sum = 0;
        int maxLength = -1;
        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (left <= right && sum > total - x) {
                sum -= nums[left];
                left++;
            }

            if (sum == total - x) {
                maxLength = max(maxLength, right - left + 1);
            }
        }
        
        return maxLength == -1 ? -1 : n - maxLength;
    }
};