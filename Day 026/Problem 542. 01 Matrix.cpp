class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dist(mat.size(),
                                 vector<int>(mat[0].size(), INT_MAX));

        queue<pair<int, int>> q;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> entry = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = entry.first + dx[i];
                int y = entry.second + dy[i];

                if (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size() &&
                    dist[x][y] == INT_MAX) {
                        dist[x][y] = dist[entry.first][entry.second] + 1;
                        q.push({x, y});
                }
            }
        }

        return dist;
    }
};