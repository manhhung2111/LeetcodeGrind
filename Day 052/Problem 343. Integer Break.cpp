class Solution {
public:

    unordered_map<int, int> dp;
    int solve(int n) {
        if (n == 1) {
            return 1;
        }

        if (dp.find(n) != dp.end()) {
            return dp[n];
        }

        int product = 1;
        for (int i = 1; i <= n - 1; i++) {
            int left = max(i, solve(i));
            int right = max(n - i, solve(n - i));

            product = max(product, left * right);
        }

        return dp[n] = product;
    }

    int integerBreak(int n) {
        return solve(n);
    }
};