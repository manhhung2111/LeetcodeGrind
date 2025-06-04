#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int dirs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    void dfs(int i, int j, const vector<vector<int>> &grid, const int &parentId, int &area, vector<vector<int>> &parent) {
        for (int k = 0; k < 4; k++) {
            int newI = i + dirs[k][0];
            int newJ = j + dirs[k][1];

            if (newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid.size() && parent[newI][newJ] == -1 && grid[newI][newJ] == 1) {
                parent[newI][newJ] = parentId;
                area++;
                dfs(newI, newJ, grid, parentId, area, parent);
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> parent(n, vector<int>(n, -1));
        unordered_map<int, int> areaMap;
        int parentId = 0;
        int result = 0;

        // Find area for each region in grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (parent[i][j] == -1 && grid[i][j] == 1) {
                    parent[i][j] = parentId;
                    int area = 1;
                    dfs(i, j, grid, parentId, area, parent);
                    areaMap[parentId] = area;
                    result = max(result, area);
                    parentId++;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int area = 1;

                    for (int k = 0; k < 4; k++) {
                        int newI = i + dirs[k][0];
                        int newJ = j + dirs[k][1];

                        if (newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid.size() && seen.find(parent[newI][newJ]) == seen.end() && grid[newI][newJ] == 1) {
                            seen.insert(parent[newI][newJ]);
                            area += areaMap[parent[newI][newJ]];
                        }
                    }

                    result = max(result, area);
                }
            }
        }

        return result;
    }
};