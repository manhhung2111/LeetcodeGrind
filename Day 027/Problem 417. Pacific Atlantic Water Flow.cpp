class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int sr, int sc) {
        if (visited[sr][sc]) return;
        visited[sr][sc] = true;

        for (int i = 0; i < 4; i++) {
            int x = sr + dx[i];
            int y = sc + dy[i];

            if (x >= 0 && x < heights.size() && y >=0 && y < heights[0].size()) {
                if (!visited[x][y] && heights[x][y] >= heights[sr][sc]) {
                    dfs(heights, visited, x, y);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));

        for (int i = 0; i < heights.size(); i++) {
            if (!pacific[i][0]) {
                dfs(heights, pacific, i, 0);
            }

            if (!atlantic[i][heights[i].size() - 1]) {
                dfs(heights, atlantic, i, heights[i].size() - 1);
            }
        }

        for (int i = 0; i < heights[0].size(); i++) {
            if (!pacific[0][i]) {
                dfs(heights, pacific, 0, i);
            }

            if (!atlantic[heights.size() - 1][i]) {
                dfs(heights, atlantic, heights.size() - 1, i);
            }
        }


        vector<vector<int>> result;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                if (atlantic[i][j] && pacific[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};