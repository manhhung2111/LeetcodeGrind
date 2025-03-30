class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastOccurrence;
        for (int i = 0; i < s.size(); i++) {
            lastOccurrence[s[i]] = i;
        }

        vector<int> result;
        int lastIndex = lastOccurrence[s[0]], startIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            if (lastIndex == i && lastOccurrence[s[i]] == lastIndex) {
                result.push_back(lastIndex - startIndex + 1);
                if (i < s.size() - 1) {
                    lastIndex = lastOccurrence[s[i+1]];
                    startIndex = i + 1;
                }
            } else {
                lastIndex = max(lastOccurrence[s[i]], lastIndex);
            }
        }

        return result;
    }
};