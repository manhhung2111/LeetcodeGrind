class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));

        queue<tuple<int, int, int, int>> q;  // i, j, remaining k, steps
        q.push({0, 0, k, 0});
        visited[0][0][k] = true;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [i, j, remK, steps] = q.front();
            q.pop();

            if (i == m - 1 && j == n - 1) return steps;

            for (auto& [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    int nextK = remK - grid[ni][nj];
                    if (nextK >= 0 && !visited[ni][nj][nextK]) {
                        visited[ni][nj][nextK] = true;
                        q.push({ni, nj, nextK, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};
