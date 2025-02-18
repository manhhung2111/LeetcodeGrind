class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size()-1, left = 0, right = matrix[0].size() - 1;

        vector<int> answer;
        while (top <= bottom && left <= right) {
            // Push the top row
            for (int i = left; i <= right; i++) {
                answer.push_back(matrix[top][i]);
            }
            top++;

            // Push the right column
            for (int i = top; i <= bottom; i++) {
                answer.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                // Push bottom row
                for (int i = right; i >= left; i--) {
                    answer.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                // Push left column
                for (int i = bottom; i >= top; i--) {
                    answer.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return answer;
    }
};