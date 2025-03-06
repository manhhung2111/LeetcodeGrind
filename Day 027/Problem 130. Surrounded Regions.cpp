class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int sr, int sc) {
        if (visited[sr][sc]) return;
        visited[sr][sc] = true;

        for (int i = 0; i < 4; i++) {
            int x = sr + dx[i];
            int y = sc + dy[i];

            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
                if (board[x][y] == 'O' && !visited[x][y]) {
                    dfs(board, visited, x, y);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited (board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                dfs(board, visited, i, 0);
            }

            if (board[i][board[i].size() - 1] == 'O' && !visited[i][board[i].size() - 1]) {
                dfs(board, visited, i, board[i].size() - 1);
            }
        }

        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 'O' && !visited[0][i]) {
                dfs(board, visited, 0, i);
            }

            if (board[board.size() - 1][i] == 'O' && !visited[board.size() - 1][i]) {
                dfs(board, visited, board.size() - 1, i);
            }
        }


        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (!visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};