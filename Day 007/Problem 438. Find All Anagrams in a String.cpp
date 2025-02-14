class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> mp1, mp2;

        for (char c : p) {
            mp2[c]++;
        }

        vector<int> answer;

        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            mp1[s[windowEnd]]++;

            if (windowEnd - windowStart + 1 == p.size()) {
                if (mp1 == mp2) {
                    answer.push_back(windowStart);
                }
                mp1[s[windowStart]]--;
                if (mp1[s[windowStart]] == 0) {
                    mp1.erase(s[windowStart]);
                }
                windowStart++;
            }
        }

        if (mp1 == mp2) {
            answer.push_back(windowStart);
        }

        return answer;
    }
};