class Solution {
public:
    string standardize(string s) {
        map<char, char> mp;
        int count = 0;

        string answer = "";
        for (char c : s) {
            if (mp.find(c) == mp.end()) {
                mp[c] = 'a' + count;
                count++;
            }
            answer += mp[c];
        }

        return answer;
    }

    bool isIsomorphic(string s, string t) {
        return standardize(s) == standardize(t);
    }
};