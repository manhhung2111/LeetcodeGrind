class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        if (n == 0) return false;
        if (s[0] == '1' || s[n - 1] == '1') return false;

        vector<bool> dp(n, false);
        dp[0] = true;

        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            if (!dp[i]) { // This index is not reachable from previous indices, so we wont jump from this index
                continue;
            }

            start = max(end + 1, i + minJump); // skip redundant works
            end = min(n - 1, i + maxJump); // avoid overflow

            for (int j = start; j <= end; j++) {
                if (s[j] == '0') {
                    dp[j] = true;
                }
            }

            if (dp[n - 1]) return true;
        }

        return dp[n - 1];
    }
};