class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // Formula: total number of subarrays - number of subarrays where max elements appears less than K times
        int maxElement = nums[0];
        for (int num : nums) {
            maxElement = max(maxElement, num);
        }

        int countMax = 0;
        int left = 0;
        long long result = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == maxElement) {
                countMax++;
            }

            while (countMax >= k) {
                if (nums[left] == maxElement) {
                    countMax--;
                }
                left++;
            }

            result += (long long)(right + 1) - (long long)(right - left + 1);
        }

        return result;
    }
};