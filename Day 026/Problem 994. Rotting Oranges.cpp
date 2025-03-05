class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int freshOranges = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        int time = 0;
        map<pair<int, int>, bool> visited;

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                pair<int, int> entry = q.front(); q.pop();

                for (int k = 0; k < 4; k++) {
                    int x = entry.first + dx[k];
                    int y = entry.second + dy[k];

                    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                        if (visited[{x, y}] == false && grid[x][y] == 1) {
                            freshOranges--;
                            visited[{x, y}] = true;
                            q.push({x, y});
                        }
                    }
                }
            }

            if (q.size() > 0) {
                time++;
            }
        }

        return freshOranges == 0 ? time : -1;
    }
};