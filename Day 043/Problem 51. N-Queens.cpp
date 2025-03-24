class Solution {
public:

    map<int, vector<pair<int, int>>> posDia, negDia;
    bool isValid (int row, int col, vector<string> &board) {
        for (int i = 0; i < board.size(); i++) {
            if (board[row][i] == 'Q') return false;
            if (board[i][col] == 'Q') return false;
        }

        for (pair<int, int> entry : posDia[row - col]) {
            auto [i , j] = entry;
            if (board[i][j] == 'Q') return false;
        }

        for (pair<int, int> entry : negDia[row + col]) {
            auto [i , j] = entry;
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    vector<vector<string>> result;
    void solve(int row, vector<string> &board) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }

        for (int i = 0; i < board.size(); i++) {
            if (isValid(row, i, board)) {
                board[row][i] = 'Q';
                solve(row + 1, board);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                posDia[i - j].push_back({i, j});
                negDia[i + j].push_back({i, j});
            }
        }

        vector<string> board(n, string(n, '.'));
        solve(0, board);

        return result;
    }
};