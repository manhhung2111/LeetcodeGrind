class Solution {
public:

    void dfs(int node, vector<int> &color, vector<vector<int>> &adj, vector<int> &result) {
        color[node] = 1;

        for (int neighbor : adj[node]) {
            if (color[neighbor] == 0) {
                dfs(neighbor, color, adj, result);
            } else if (color[neighbor] == 1) {
                return;
            }
        }

        color[node] = 2;
        result.push_back(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> color (numCourses, 0);
        vector<vector<int>> adj (numCourses);

        for (vector<int>edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]); // edge[1] → edge[0] (dependency)
        }

        vector<int> result;
        for (int i = 0; i < numCourses; i++) {
            if (color[i] == 0) {
                dfs(i, color, adj, result);
            }
        }

        if (result.size() != numCourses) return {};
        if (result.size() > 1) reverse(result.begin(), result.end());

        return result;
    }
};