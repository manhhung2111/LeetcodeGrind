class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;

        int windowStart = 0;
        int answer = 0;

        for (int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            mp[s[windowEnd]]++;

            while (mp[s[windowEnd]] > 1) {
                mp[s[windowStart]]--;
                windowStart++;
            }

            answer = max(windowEnd - windowStart + 1, answer);
        }

        return answer;
    }
};