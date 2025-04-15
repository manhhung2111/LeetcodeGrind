class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1, mp2;
        for (char c : s1) mp1[c]++;

        int start = 0;
        for (int end = 0; end < s2.size(); end++) {
            mp2[s2[end]]++;

            if (mp1 == mp2) {
                return true;
            }

            while (mp1[s2[end]] < mp2[s2[end]]) {
                mp2[s2[start]]--;
                start++;
            }
        }

        return false;
    }
};