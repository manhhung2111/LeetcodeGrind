class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());

        long long result = 0;
        int left = 0, countMaxElement = 0;
        for (int right = 0; right < nums.size(); right++) {
            countMaxElement += (nums[right] == maxElement);

            while (countMaxElement >= k) {
                countMaxElement -= (nums[left] == maxElement);
                left++;
            }

            result += (right + 1) - (right - left + 1);
        }

        return result;
    }
};