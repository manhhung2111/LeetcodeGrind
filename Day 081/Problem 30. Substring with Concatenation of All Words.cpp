class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        int wordLen = words[0].size();
        if (s.size() < n * wordLen) return {};

        unordered_map<string, int> sample;
        for (string word : words) {
            sample[word]++;
        }

        vector<int> result;
        for (int i = 0; i <= s.size() - n * wordLen; i++) {
            if (valid(i, wordLen, n, s, sample)) {
                result.push_back(i);
            }
        }

        return result;
    }

    bool valid(int &index, int &wordLen, int &n, string &s, unordered_map<string, int> &sample) {
        unordered_map<string, int> count;
        for (int i = 0; i < wordLen * n; i += wordLen) {
            string substr = s.substr(i + index, wordLen);
            if (sample.find(substr) == sample.end()) {
                return false;
            }
            count[substr]++;
        }

        return count == sample;
    }
};