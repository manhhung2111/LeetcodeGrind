class Solution {
public:
    bool isEqual(vector<int> &count1, vector<int> &count2) {
        for (int i = 0; i < count1.size(); i++) {
            if (count1[i] != count2[i]) return false;
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> count1(26, 0), count2(26, 0);

        for (char c : p) {
            count2[c - 'a']++;
        }

        vector<int> answer;

        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            count1[s[windowEnd] - 'a']++;

            if (windowEnd - windowStart + 1 == p.size()) {
                if (isEqual(count1, count2)) {
                    answer.push_back(windowStart);
                }

                count1[s[windowStart] - 'a']--;
                windowStart++;
            }
        }

        return answer;
    }
};