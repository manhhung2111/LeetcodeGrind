class Solution {
public:
    void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited) {
        if (visited[node]) return;
        visited[node] = true;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) dfs(neighbor, graph, visited);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int cables = connections.size();
        if (cables < n - 1) return -1;

        vector<vector<int>> graph(n);
        for (vector<int> connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }

        vector<bool> visited (n, false);

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited);
                count++;
            }
        }

        return count - 1;
    }
};