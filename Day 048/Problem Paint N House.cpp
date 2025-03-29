
class Solution {   
public:
    map<pair<int, int>, long long> dp;  // Use int instead of string for colors

    long long solve(int index, int N, int prevColor, int r[], int g[], int b[]) {
        if (index == N) return 0;  // Base case: no more houses left

        if (dp.find({index, prevColor}) != dp.end()) {
            return dp[{index, prevColor}];
        }

        long long minCost = LLONG_MAX;

        for (int color = 0; color < 3; color++) {
            if (color != prevColor) {
                long long cost = 0;
                if (color == 0) cost = r[index];  // Red
                if (color == 1) cost = g[index];  // Green
                if (color == 2) cost = b[index];  // Blue

                minCost = min(minCost, cost + solve(index + 1, N, color, r, g, b));
            }
        }

        return dp[{index, prevColor}] = minCost;
    }

    long long int distinctColoring(int N, int r[], int g[], int b[]) {
        return solve(0, N, -1, r, g, b);  // Start with no previous color (-1)
    }
};