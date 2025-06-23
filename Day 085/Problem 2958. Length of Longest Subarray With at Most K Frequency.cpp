class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        int result = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            countMap[nums[right]]++;

            while (countMap[nums[right]] > k) {
                countMap[nums[left++]]--;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};