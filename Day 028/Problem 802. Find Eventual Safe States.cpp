class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n, 0);

        // Transpose graph
        vector<vector<int>> transposeGraph(n);
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                indegree[i]++;
                transposeGraph[neighbor].push_back(i);
            }
        }

        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> result;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            result.push_back(node);

            for (int neighbor : transposeGraph[node]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        if (result.size() > 1) sort(result.begin(), result.end());

        return result;
    }
};