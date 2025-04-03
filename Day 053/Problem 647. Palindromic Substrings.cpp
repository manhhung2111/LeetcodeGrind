class Solution {
public:
    int solve(int left, int right, string s) {
        int count = 0;
        while (left >=0 && right < s.size()) {
            if (s[left--] != s[right++]) {
                return count;
            }

            count++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            count += solve(i, i, s);
        }

        for (int i = 0; i < s.size() - 1; i++) {
            count += solve(i, i + 1, s);
        }

        return count;
    }
};