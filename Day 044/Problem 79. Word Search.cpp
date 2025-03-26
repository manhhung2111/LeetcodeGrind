class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    bool dfs(int r, int c, vector<vector<char>> &board, string word, int index, map<pair<int, int>, bool> &visited) {
        if (index == word.size()) {
            return true;
        } else if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) {
            return false;
        } else if (visited[{r, c}] == true || board[r][c] != word[index]) {
            return false;
        }

        visited[{r, c}] = true;

        for (int i = 0; i < 4; i++) {
            int row = r + dx[i];
            int col = c + dy[i];

            if (dfs(row, col, board, word, index + 1, visited)) {
                return true;
            }
        }

        visited[{r, c}] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        map<pair<int, int>, bool> visited;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int index = 0;
                if (dfs(i, j, board, word, index, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};