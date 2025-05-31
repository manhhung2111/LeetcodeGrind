#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    int minTimeToReach(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        
        while (!pq.empty()) {
            auto [currentTime, row, col] = pq.top(); pq.pop();
            if (currentTime > dist[row][col]) continue;

            for (int k = 0; k < 4; k++) {
                int i = row + dirs[k][0];
                int j = col + dirs[k][1];

                if (i >= 0 && i < n && j >= 0 && j < m) {
                    int waitingTime = max(0, grid[i][j] - currentTime);
                    int expectedTime = currentTime + waitingTime + 1;

                    if (expectedTime < dist[i][j]) {
                        dist[i][j] = expectedTime;
                        pq.push({expectedTime, i, j});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};