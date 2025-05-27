class Solution {
public:
    bool isVowel(char &c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix = {0};
        for (string word : words) {
            if (isVowel(word.front()) && isVowel(word.back())) {
                prefix.push_back(prefix.back() + 1);
            } else {
                prefix.push_back(prefix.back());
            }
        }

        vector<int> result;
        for (vector<int> query : queries) {
            result.push_back(prefix[query[1] + 1] - prefix[query[0]]);
        }

        return result;
    }
};