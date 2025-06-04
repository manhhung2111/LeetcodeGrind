class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        queue<tuple<int, int, int>> q;
        
        visited[0][0][k] = true;
        q.push({0, 0, k});

        int steps = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto [row, col, eliminationCount] = q.front(); q.pop();
                if (row == m - 1 && col == n - 1) {
                    return steps;
                }

                for (int k = 0; k < 4; k++) {
                    int newRow = row + dirs[k][0];
                    int newCol = col + dirs[k][1];

                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                        if (grid[newRow][newCol] == 1 && eliminationCount > 0 && visited[newRow][newCol][eliminationCount - 1] == false) {
                            visited[newRow][newCol][eliminationCount - 1] = true;
                            q.push({newRow, newCol, eliminationCount - 1});
                        } else if (grid[newRow][newCol] == 0 && visited[newRow][newCol][eliminationCount] == false) {
                            visited[newRow][newCol][eliminationCount] = true;
                            q.push({newRow, newCol, eliminationCount});
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};