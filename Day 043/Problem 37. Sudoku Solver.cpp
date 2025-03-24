class Solution {
public:
    bool isValid(int row, int col, char value, vector<vector<char>> &board) {
        // Column validation
        for (int i = 0; i < 9; i++) {
            if (value == board[i][col]) return false;
        }

        // Row validation
        for (int i = 0; i < 9; i++) {
            if (value == board[row][i]) return false;
        }

        // Sub-boxes validation
        int boxRow = row / 3, boxCol = col / 3;
        for (int i = boxRow * 3; i < boxRow * 3 + 3; i++) {
            for (int j = boxCol * 3; j < boxCol * 3 + 3; j++) {
                if (board[i][j] == value) return false;
            }
        }

        return true;
    }

    bool solve(int row, int col, vector<vector<char>> &board) {
        if (row == 9) {
            return true;
        } else if (col == 9) {
            return solve(row + 1, 0, board);
        } else if (board[row][col] != '.') {
            return solve(row, col + 1, board);
        } else {
            for (char c = '1'; c <= '9'; c++) {
                if (isValid(row, col, c, board)) {
                    board[row][col] = c;
                    if (solve(row, col + 1, board)) {
                        return true;
                    }
                    board[row][col] = '.';
                }
            }
            return false;
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, board);
    }
};