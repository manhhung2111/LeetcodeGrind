class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        effort[0][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0}); // {effort, colIndex, rowIndex}

        while (!pq.empty()) {
            auto [effortLevel, row, col] = pq.top(); pq.pop();
            if (effortLevel > effort[row][col]) continue;

            for (int k = 0; k < 4; k++) {
                int i = row + dx[k];
                int j = col + dy[k];

                if (i >= 0 && i < rows && j >= 0 && j < cols) {
                    if (effort[i][j] > max(effort[row][col], abs(heights[i][j] - heights[row][col]))) {
                        effort[i][j] = max(effort[row][col], abs(heights[i][j] - heights[row][col]));
                        pq.push({effort[i][j], i, j});
                    }
                }
            }
        }

        return effort[rows-1][cols-1];
    }
};