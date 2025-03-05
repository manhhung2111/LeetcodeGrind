class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    void dfs(int i, int j, vector<vector<char>> &grid, map<pair<int, int>, bool> &visited) {
        visited[{i ,j}] = true;

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                if (grid[x][y] == '1' && visited[{x, y}] == false) {
                    dfs(x, y, grid, visited);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        map<pair<int, int>, bool> visited;
        int result = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && visited[{i, j}] == false) {
                    dfs(i, j, grid, visited);
                    result++;
                }
            }
        }


        return result;
    }
};