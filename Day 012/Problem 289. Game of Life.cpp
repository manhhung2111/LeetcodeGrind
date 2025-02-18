class Solution {
public:
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int surrounding_live_cells(vector<vector<int>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        int answer = 0;
        for (int k = 0; k < 8; k++) {
            int new_i = i + dx[k];
            int new_j = j + dy[k];
            if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
                if (board[new_i][new_j] == 1)
                    answer++;
            }
        }
        return answer;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> tmp = board;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int live_cells = surrounding_live_cells(tmp, i, j);
                if (board[i][j] == 1) {
                    if (live_cells < 2 || live_cells > 3)
                        board[i][j] = 0;
                } else {
                    if (live_cells == 3)
                        board[i][j] = 1;
                }
            }
        }
    }
};