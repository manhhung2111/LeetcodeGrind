class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums.back();
        vector<int> dp (n, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];

        for (int i = 2; i < n; i++) {
            int maxRob = 0;
            for (int j = 0; j <= i - 2; j++) {
                maxRob = max(dp[j], maxRob);
            }
            dp[i] = maxRob + nums[i];
        }

        return max(dp[n-1], dp[n-2]);
    }
};