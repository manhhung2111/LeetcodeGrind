class Solution {
public:
    string helper(int left, int right, string s) {
        string result = "";

        while (left >= 0 && right < s.size()) {
            if (s[left] != s[right]) {
                return result;
            }

            result = s.substr(left, right - left + 1);
            left--; right++;
        }

        return result;
    }

    string longestPalindrome(string s) {
        if (s.size() == 1) return s;
        string result = "";

        for (int i = 0; i < s.size() - 1; i++) {
            string temp1 = helper(i, i, s);
            string temp2 = helper(i, i + 1, s);

            if (temp1.size() > result.size()) {
                result = temp1;
            }
            
            if (temp2.size() > result.size()) {
                result = temp2;
            }
        }

        return result;
    }
};