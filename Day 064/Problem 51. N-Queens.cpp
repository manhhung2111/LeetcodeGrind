class Solution {
public:
    vector<vector<string>> result;
    void solve(int row, vector<string> &board, unordered_map<int, bool> &positiveDiag, unordered_map<int, bool> &negativeDiag, unordered_map<int, bool> &cols) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); col++) {
            if (positiveDiag[row + col] == false && negativeDiag[row - col] == false && cols[col] == false) {
                positiveDiag[row + col] = true;
                negativeDiag[row - col] = true;
                cols[col] = true;
                board[row][col] = 'Q';

                solve(row + 1, board, positiveDiag, negativeDiag, cols);

                board[row][col] = '.';
                positiveDiag[row + col] = false;
                negativeDiag[row - col] = false;
                cols[col] = false;
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        unordered_map<int, bool> positiveDiag, negativeDiag;
        unordered_map<int, bool> cols;
        solve(0, board, positiveDiag, negativeDiag, cols);

        return result;
    }
};