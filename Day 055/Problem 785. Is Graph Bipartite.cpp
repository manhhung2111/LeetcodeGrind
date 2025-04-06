class Solution {
public:

    bool bfs(int src, const vector<vector<int>>& graph, vector<int> &color) {
        queue<int> q;
        q.push(src);
        color[src] = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();

            for (int neighbor : graph[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                } else if (color[neighbor] != 1 - color[node]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color (graph.size(), -1);

        for (int node = 0; node < graph.size(); node++) {
            if (color[node] == -1) {
                if (!bfs(node, graph, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};