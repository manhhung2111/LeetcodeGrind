class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    void dfs(vector<vector<int>>& image, pair<int, int> coordinate, int originalColor, int color, map<pair<int, int>, bool> &visited) {
        int row = coordinate.first, col = coordinate.second;

        image[row][col] = color;
        visited[{row, col}] = true;

        for (int i = 0; i < 4; i++) {
            int x = row + dx[i];
            int y = col + dy[i];

            if (x >= 0 && x < image.size() && y >= 0 && y < image[0].size() && image[x][y] == originalColor && !visited[{x, y}]) {
                dfs(image, {x, y}, originalColor, color, visited);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        map<pair<int, int>, bool> visited;
        int originalColor = image[sr][sc];
        dfs(image, {sr, sc}, originalColor, color, visited);

        return image;
    }
};