class Solution {
private:
    int subarraysWithAtMostK(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        int result = 0, left = 0;

        for (int right = 0; right < nums.size(); right++) {
            countMap[nums[right]]++;

            while (countMap.size() > k) {
                countMap[nums[left]]--;
                if (countMap[nums[left]] == 0) {
                    countMap.erase(nums[left]);
                }
                left++;
            }

            result += right - left + 1;
        }

        return result;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtMostK(nums, k) - subarraysWithAtMostK(nums, k - 1);
    }
};