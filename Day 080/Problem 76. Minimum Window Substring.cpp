#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> neededMap, havingMap;
        for (char c : t) {
            neededMap[c]++;
        }

        int having = 0, needed = neededMap.size();
        int left = 0;
        int index = -1, len = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            havingMap[s[right]]++;

            if (neededMap.find(s[right]) != neededMap.end() && havingMap[s[right]] == neededMap[s[right]]) {
                having++;
            }

            while (having == needed) {
                if (right - left + 1 < len) {
                    index = left;
                    len = right - left + 1;
                }
                havingMap[s[left]]--;

                if (neededMap.find(s[left]) != neededMap.end() && havingMap[s[left]] < neededMap[s[left]]) {
                    having--;
                }
                left++;
            }
        }

        if (index == -1) return "";
        return s.substr(index, len);
    }
};