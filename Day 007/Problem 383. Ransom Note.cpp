class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp1, mp2;

        for (char c : ransomNote) {
            mp1[c]++;
        }

        for (char c : magazine) {
            mp2[c]++;
        }

        for (char c : ransomNote) {
            if (mp1[c] > mp2[c]) {
                return false;
            }
        }

        return true;
    }
};