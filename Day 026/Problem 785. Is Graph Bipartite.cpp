class Solution {
public:
    bool bfs(vector<vector<int>>& graph, int node, map<int, bool> &visited, vector<int> &color) {
        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int currNode = q.front(); q.pop();

            for (int neighbour : graph[currNode]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    color[neighbour] = color[currNode] == 1 ? 0 : 1;
                } else {
                    if (color[neighbour] == color[currNode]) return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size());
        map<int, bool> visited;

        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                color[i] = 0;
                if (!bfs(graph, i, visited, color)) return false;
            }
        }

        return true;
    }
};