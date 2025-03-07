class Solution {
public:
    bool dfs(int node, vector<int> &color, vector<vector<int>> &adj) {
        color[node] = 1;

        for (int neighbor : adj[node]) {
            if (color[neighbor] == 0 && dfs(neighbor, color, adj)) {
                return true;
            } else if (color[neighbor] == 1) {
                return true;
            }
        }

        color[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> color (numCourses, 0);
        vector<vector<int>> adj (numCourses);

        for (vector<int> courses : prerequisites) {
            adj[courses[1]].push_back(courses[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (color[i] == 0 && dfs(i, color, adj)) {
                return false;
            }
        }

        return true;
    }
};