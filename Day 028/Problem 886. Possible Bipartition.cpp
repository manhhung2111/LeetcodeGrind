class Solution {
public:
    bool dfs(int source, vector<int> &color, vector<vector<int>> &adj) {
        for (int neighbor : adj[source]) {
            if (color[neighbor] == -1) {
                color[neighbor] = color[source] == 1 ? 0 : 1;
                if (!dfs(neighbor, color, adj)) {
                    return false;
                }
            } else if (color[neighbor] != -1 && color[neighbor] == color[source]) {
                return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color (n+1, -1); 
        vector<vector<int>> adj (n+1);

        for (vector<int> row : dislikes) {
            adj[row[0]].push_back(row[1]);
            adj[row[1]].push_back(row[0]);
        }

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!dfs(i, color, adj)) {
                    return false;
                }
            }
        }

        return true;
    }
};