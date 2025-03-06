class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<pair<int, vector<int>>> q;
        q.push({0, {0}});

        vector<vector<int>> result;
        while (!q.empty()) {
            pair<int, vector<int>> entry = q.front(); q.pop();

            int node = entry.first;
            vector<int> path = entry.second;

            for (int neighbour : graph[node]) {
                vector<int> newPath = path;
                newPath.push_back(neighbour);

                if (neighbour == graph.size() - 1) {
                    result.push_back(newPath);
                }

                q.push({neighbour, newPath});
            }
        }

        return result;
    }
};