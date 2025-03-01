class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        if (nums.size() > 1) sort(nums.begin(), nums.end());

        int MOD = 1e9 + 7;
        int left = 0, right = nums.size() - 1;
        long long result = 0;

        // Strore remainders
        vector<long long> remainders(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            remainders[i] = (remainders[i-1] * 2) % MOD;
        }

        while (left <= right) {
            while (left <= right && nums[left] + nums[right] > target) {
                right--;
            }

            if (left <= right) {
                result += remainders[right -left];
                result = result % MOD;
            }

            left++;
        }


        return result;
    }
};