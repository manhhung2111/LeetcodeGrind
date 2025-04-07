class Solution {
public:
    bool isValidPos(int row, int col, char val, const vector<vector<char>>& board) {
        // Row validation
        for (int i = 0; i < board[0].size(); i++) {
            if (board[row][i] == val) {
                return false;
            }
        }

        // Col validation
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == val) {
                return false;
            }
        }

        // Sub-grid validation
        int rowGrid = row / 3 * 3;
        int colGrid = col / 3 * 3;
        for (int i = rowGrid; i < rowGrid + 3; i++) {
            for (int j = colGrid; j < colGrid + 3; j++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }

        return true;
    }   

    bool solve(int row, int col, vector<vector<char>> &board) {
        if (row == board.size()) {
            return true;
        }

        if (col == board[0].size()) {
            return solve(row + 1, 0, board);
        }

        if (board[row][col] != '.') {
            return solve(row, col + 1, board);
        }

        for (char c = '1'; c <= '9'; c++) {
            if (isValidPos(row, col, c, board)) {
                board[row][col] = c;
                if (solve(row, col + 1, board)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }

        return false;
    }


    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, board);
    }
};