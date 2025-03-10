class Solution {
public:
    vector<vector<int>> result;
    void dfs(int node, vector<vector<int>> &graph, vector<int> &disc, vector<int> &low, int parent) {
        static int time = 0;
        disc[node] = low[node] = time;
        time++;

        for (int neighbor : graph[node]) {
            if (disc[neighbor] == -1) {
                dfs(neighbor, graph, disc, low, node);
                low[node] = min(low[node], low[neighbor]);

                if (low[neighbor] > disc[node]) {
                    result.push_back({node, neighbor});
                }
            } else if (neighbor != parent) {
                low[node] = min(disc[neighbor], low[node]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int node = 0, parent = -1;
        vector<int> disc(n, -1), low(n, -1);

        vector<vector<int>> graph(n);
        for (vector<int> connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }

        dfs(node, graph, disc, low, parent);
        return result;
    }
};