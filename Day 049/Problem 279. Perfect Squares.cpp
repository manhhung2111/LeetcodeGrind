class Solution {
public:
    unordered_map<int, int> dp;
    int solve(const vector<int> &candidates, int target) {
        if (target == 0) {
            return 0;
        }

        if (target < 0) {
            return INT_MAX - 1;
        }

        if (dp.find(target) != dp.end()) {
            return dp[target];
        }

        int minCost = INT_MAX;
        for (int candidate : candidates) {
            minCost = min(minCost, 1 + solve(candidates, target - candidate * candidate));
        }

        return dp[target] = minCost;
    }

    int numSquares(int n) {
        vector<int> candidates;
        for (int i = 1; i <= sqrt(n); i++) {
            candidates.push_back(i);
        }

        return solve(candidates, n);
    }
};