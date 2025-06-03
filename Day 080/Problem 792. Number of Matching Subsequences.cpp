class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<int, int>>> waitingChar(128);

        for (int i = 0; i < words.size(); i++) {
            waitingChar[words[i][0] - 'a'].push_back(
                {i, 0}); // {wordIndex, waitingIndex}
        }

        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            vector<pair<int, int>> waitingList = waitingChar[c - 'a'];
            waitingChar[c - 'a'].clear();

            for (auto& [wordIndex, waitingIndex] : waitingList) {
                if (waitingIndex + 1 == words[wordIndex].size()) {
                    result++;
                } else {
                    waitingChar[words[wordIndex][waitingIndex + 1] - 'a']
                        .push_back({wordIndex, waitingIndex + 1});
                }
            }
        }

        return result;
    }
};