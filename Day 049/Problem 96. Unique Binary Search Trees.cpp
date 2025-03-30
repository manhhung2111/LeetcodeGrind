class Solution {
public:
    int numTrees(int n) {
        unordered_map<int, int> dp = {
            {0, 1},
            {1, 1},
            {2, 2},
            {3, 5}
        };

        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};