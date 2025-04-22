class Solution {
public:

    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    bool solve(pair<int, int> coordinate, int index, string word, const vector<vector<char>> &board, vector<vector<bool>> &visited) {
        if (index == word.size()) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int x = coordinate.first + dx[i];
            int y = coordinate.second + dy[i];

            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == word[index] && !visited[x][y]) {
                visited[x][y] = true;
                if (solve({x, y}, index + 1, word, board, visited)){
                    return true;
                }
                visited[x][y] = false;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    visited[i][j] = true;
                    if (solve({i, j}, 1, word, board, visited)) {
                        return true;
                    }
                }
            }
        }


        return false;
    }
};