class Solution {
public:

    unordered_map<int, int> dp;
    int solve(int n) {
        if (n == 0) {
            return dp[n] = 0;
        }

        if (n == 1 || n < 0) {
            return dp[n] = -1;
        }

        if (dp.find(n) != dp.end()) {
            return dp[n];
        }

        int left = solve(n - 2);
        int right = solve(n - 3);

        if (left == -1 && right == -1) {
            return dp[n] = -1;
        } else if (left == -1) {
            return dp[n] = 1 + right;
        } else if (right == -1) {
            return dp[n] = 1 + left;
        }

        return dp[n] = 1 + min(left, right);
    }

    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int result = 0;
        for (auto& [num, count] : freq) {
            int operations = solve(count);
            if (operations == -1) {
                return -1;
            }
            result += operations;
        }

        return result;
    }
};