class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    int swimInWater(vector<vector<int>>& grid) {
        // Using dijkstra in grid
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = grid[0][0];

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({dist[0][0], 0, 0});

        while (!pq.empty()) {
            auto [weight, row, col] = pq.top(); pq.pop();
            if (weight > dist[row][col]) continue;

            for (int k = 0; k < 4; k++) {
                int i = row + dirs[k][0];
                int j = col + dirs[k][1];

                if (i >= 0 && i < n && j >= 0 && j < m) {
                    int cost = max(dist[row][col], grid[i][j]);
                    if (dist[i][j] > cost) {
                        dist[i][j] = cost;
                        pq.push({cost, i, j});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};