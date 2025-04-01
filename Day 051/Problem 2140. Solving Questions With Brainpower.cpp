class Solution {
public:

    unordered_map<int, long long> dp;
    long long solve(int index, const vector<vector<int>> &questions) {
        if (index == questions.size() - 1) {
            return questions.back()[0];
        }

        if (index >= questions.size()) {
            return 0;
        }

        if (dp.find(index) != dp.end()) {
            return dp[index];
        }

        long long take = questions[index][0] + solve(index + questions[index][1] + 1, questions);
        long long skip = solve(index + 1, questions);

        return dp[index] = max(take, skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        return solve(0, questions);
    }
};