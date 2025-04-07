class Solution {
public:
    unordered_map<int, bool> negDiag, posDiag, cols, rows;

    bool isValid(int row, int col) {
        return rows[row] == false && cols[col] == false && negDiag[row - col] == false && posDiag[row + col] == false;
    }

    void solve(int row, vector<string> &board, vector<vector<string>> &result) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); col++) {
            if (isValid(row, col)) {
                board[row][col] = 'Q';
                
                rows[row] = true;
                cols[col] = true;
                negDiag[row - col] = true;
                posDiag[row + col] = true;

                solve(row + 1, board, result);

                rows[row] = false;
                cols[col] = false;
                negDiag[row - col] = false;
                posDiag[row + col] = false;

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;

        solve(0, board, result);

        return result;
    }
};