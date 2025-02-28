class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows (numRows);

        int row = 0, index = 0;
        bool downward = true;
        while (index < s.size()) {
            rows[row] += s[index];

            if (row == numRows - 1) downward = false;
            else if (row == 0) downward = true;

            row += downward ? 1 : -1;
            index++;
        }

        string answer = "";
        for (string row : rows) {
            answer += row;
        }

        return answer;
    }
};