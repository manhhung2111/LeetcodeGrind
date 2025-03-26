class Solution {
public:
    int solve (int left, int right, vector<int>& nums) {
        if (left > right) return 0;

        int prev2 = 0, prev1 = 0, curr = 0;

        for (int i = left; i <= right; i++) {
            curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        int first = solve(0, n - 2, nums);
        int second = solve(1, n - 1, nums);

        return max(first, second);
    }
};