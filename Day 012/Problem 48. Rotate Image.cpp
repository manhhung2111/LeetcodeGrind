class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transpose the matrix. Eg: turn the rows into the columns and vice versa
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix[i].size(); j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // Swap the columns from 0 to n/2
        for (int i = 0; i < matrix[0].size()/2; i++) {
            for (int j = 0; j < matrix.size(); j++) {
                int temp = matrix[j][i];
                matrix[j][i] = matrix[j][matrix[0].size() - 1 - i];
                matrix[j][matrix[0].size() - 1 - i] = temp;
            }
        }
    }
};