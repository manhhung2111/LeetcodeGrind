class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(), m = words2.size();
        
        vector<vector<int>> count1(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words1[i].size(); j++) {
                count1[i][words1[i][j] - 'a']++;
            }
        }

        vector<vector<int>> count2(m, vector<int>(26, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < words2[i].size(); j++) {
                count2[i][words2[i][j] - 'a']++;
            }
        }

        vector<int> unionCount(26, 0);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < m; j++) {
                unionCount[i] = max(unionCount[i], count2[j][i]);
            }
        }

        vector<string> result;
        for (int i = 0; i < n; i++) {
            bool valid = true;
            for (int j = 0; j < 26; j++) {
                if (count1[i][j] < unionCount[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                result.push_back(words1[i]);
            }
        }


        return result;
    }
};