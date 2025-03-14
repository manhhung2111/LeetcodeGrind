class Solution {
public:
    // This is a eulerian path in a directed graph
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<int, int> indegree, outdegree;
        map<int, multiset<int>> graph;
        for (vector<int> edge : pairs) {
            int source = edge[0], dest = edge[1];
            outdegree[source]++;
            indegree[dest]++;
            graph[source].insert(dest);
        }

        // Find the source vertex
        int startVertex = pairs[0][0];
        for (auto entry : outdegree) {
            if (entry.second - indegree[entry.first]  == 1) {
                startVertex = entry.first;
            }
        }

        vector<int> path;
        stack<int> stk;
        stk.push(startVertex);

        while (!stk.empty()) {
            int node = stk.top();

            if (graph[node].size() > 0) {
                auto neighbor = graph[node].begin();
                stk.push(*neighbor);
                graph[node].erase(neighbor);
            } else {
                path.push_back(node);
                stk.pop();
            }
        }

        if (path.size() > 1) reverse(path.begin(), path.end());

        vector<vector<int>> result;
        for (int i = 0; i < path.size() - 1; i++) {
            result.push_back({path[i], path[i+1]});
        }

        return result;
    }
};