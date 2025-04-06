class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1), prev(nums.size(), -1);

        int maxLength = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            maxLength = max(dp[i], maxLength);
        } 

        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (dp[i] == maxLength) {
                while (i != -1) {
                    result.push_back(nums[i]);
                    i = prev[i];
                }
                break;
            }
        }

        return result;
    }
};