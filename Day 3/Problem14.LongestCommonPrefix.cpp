#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = "";

        while (true) {
            int idx = answer.size();

            int shouldBreak = false;
            for (int i = 1; i < strs.size(); i++) {
                if (idx < strs[0].size() && idx < strs[i].size() && strs[0][idx] == strs[i][idx]) {
                    continue;
                } else {
                    shouldBreak = true;
                    break;
                }
            }
 
            // There exsits at least a string that has different character at index `idx`
            if (idx < strs[0].size() && !shouldBreak) {
                answer.push_back(strs[0][idx]);
            } else {
                break;
            }
        }

        return answer;
    }
};
