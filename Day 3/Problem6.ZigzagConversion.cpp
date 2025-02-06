#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        vector<string> rows (min(numRows, int(s.size())));

        int currentRow = 0;
        bool goingDown = true;
        for (char c : s) {
            rows[currentRow].push_back(c);

            if (currentRow == 0) {
                goingDown = true;
            } else if (currentRow == numRows - 1) {
                goingDown = false;
            }

            currentRow += goingDown ? 1 : -1;
        }

        string answer = "";
        for (string row : rows) {
            answer += row;
        }

        return answer;
    }
};