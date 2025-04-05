class Solution {
public:
    const int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        sort(nums.begin(), nums.end());
        
        long long count = 0;
        vector<long long> remainder (nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            remainder[i] = (remainder[i - 1] * 2) % MOD;
        }

        while (left <= right) {
            while (right >= 0 && nums[left] + nums[right] > target) {
                right--;
            }

            if (right < left) break;

            count = (count + remainder[right - left]) % MOD;
            left++;
        }

        return count;
    }
};