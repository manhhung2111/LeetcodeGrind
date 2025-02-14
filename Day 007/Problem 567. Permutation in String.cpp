class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> mp1, mp2;

        for (char c : s1) {
            mp1[c]++;
        }

        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < s2.size(); windowEnd++) {
            mp2[s2[windowEnd]]++;

            if (windowEnd - windowStart + 1 == s1.size()) {
                if (mp1 == mp2) return true;
                mp2[s2[windowStart]]--;
                if (mp2[s2[windowStart]] == 0) mp2.erase(s2[windowStart]);
                windowStart++;
            }
        }

        return false;
    }
};