class Solution {
public:
    vector<string> result;
    void solve(int open, int close, string &str) {
        if (open == 0 && close == 0) {
            result.push_back(str);
            return;
        }

        if (open > 0) {
            str.push_back('(');
            solve(open - 1, close, str);
            str.pop_back();
        }

        if (close > open) {
            str.push_back(')');
            solve(open, close - 1, str);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string str = "(";

        solve(n - 1, n, str);

        return result;
    }
};