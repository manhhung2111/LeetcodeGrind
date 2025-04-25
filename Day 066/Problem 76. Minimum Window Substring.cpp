class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return "";


        unordered_map<int, int> count1, count2;
        for (char c : t) count2[c]++;

        int left = 0, result = INT_MAX;
        pair<int, int> substr = {-1, -1};

        int have = 0, need = count2.size();
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            count1[c]++;

            if (count2.find(c) != count2.end() && count1[c] == count2[c]) {
                have++;
            }

            while (have == need) {
                if (right - left + 1 < result) {
                    result = right - left + 1;
                    substr = {left, right};
                }
                count1[s[left]]--;
                if (count2.find(s[left]) != count2.end() && count1[s[left]] < count2[s[left]]) {
                    have--;
                }
                left++;
            }
        }

        if (result == INT_MAX) return "";
        return s.substr(substr.first, substr.second - substr.first + 1);
    }
};