class Solution {
public:

    bool isValid(string s) {
        int num = stoi(s);
        return num >= 1 && num <= 26;
    }

    unordered_map<int, int> dp;
    int solve(int index, const string &s) {
        if (index == s.size()) {
            return 1;
        }

        if (dp.find(index) != dp.end()) {
            return dp[index];
        }

        int count = 0;
        for (int i = index; i < s.size(); i++) {
            if (isValid(s.substr(index, i - index + 1))) {
                count += solve(i + 1, s);
            } else {
                break;
            }
        }

        return dp[index] = count;
    }

    int numDecodings(string s) {
        return solve(0, s);
    }
};