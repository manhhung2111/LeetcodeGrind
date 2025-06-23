class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int result = 1, left = 0;
        for (int right = 1; right < nums.size(); right++) {
            long neededOperations = (long)(right - 1 - left + 1) * (long)(nums[right] - nums[right - 1]);
            while (neededOperations > k) {
                k += nums[right - 1] - nums[left];
                left++;
                neededOperations = (long)(right - 1 - left + 1) * (long)(nums[right] - nums[right - 1]);
            }

            k -= neededOperations;
            result = max(right - left + 1, result);
        }

        return result;
    }
};