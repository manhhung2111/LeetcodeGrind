class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<pair<int, int>, bool> zeroIndexes;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (!matrix[i][j]) {
                    zeroIndexes[{i, j}] = true;
                }
            }
        }


        for (auto entry : zeroIndexes) {
            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[entry.first.first][i] = 0;
            }


            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][entry.first.second] = 0;
            }
        }
    }
};