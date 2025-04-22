class Solution {
public:
    string solve(int left, int right, const string &s) {
        while (left >= 0 && right < s.size()) {
            if (s[left] != s[right]) {
                return s.substr(left + 1, right - 1 - (left + 1) + 1);
            }
            left--; right++;
        }

        return s.substr(left + 1, right - 1 - (left + 1) + 1);
    }

    string longestPalindrome(string s) {
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            string temp = solve(i, i, s);
            if (temp.size() > result.size()) {
                result = temp;
            }
        }

        for (int i = 0; i < s.size() - 1; i++) {
            string temp = solve(i, i + 1, s);
            if (temp.size() > result.size()) {
                result = temp;
            }
        }

        return result;
    }
};