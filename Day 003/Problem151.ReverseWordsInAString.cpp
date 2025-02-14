#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    string reverseWords(string s) {
        vector<string> words;

        int start = 0, end = 0;
        while (start < s.size() && end < s.size()) {
            if (s[start] == ' ' && s[end] == ' ') {
                start++; end++;
            } else if (s[end] == ' ') {
                string temp = "";
                for (int i = start; i < end; i++) {
                    temp.push_back(s[i]);
                }
                words.push_back(temp);
                start = end;
            } else if (s[end] != ' ') {
                end++;
            }
        }

        if (start < s.size()) {
            string temp = "";
            for (int i = start; i < end; i++) {
                temp.push_back(s[i]);
            }
            words.push_back(temp);
        }

        string answer = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            answer += words[i];
            if (i != 0) answer += " ";
        }

        return answer;
    }
};