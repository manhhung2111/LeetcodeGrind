class Solution {
public:
    int bfs(vector<vector<int>> &graph, int node, int k) {
        if (k == 0) return 1;
        if (k <= 0) return 0;

        vector<bool> visited(graph.size(), false);
        visited[node] = true;

        queue<int> q;
        q.push(node);

        int result = 0;
        while (!q.empty() && k >= 0) {
            int n = q.size();
            result += n;
            for (int i = 0; i < n; i++) {
                int curr = q.front(); q.pop();
                
                for (int neighbour : graph[curr]) {
                    if (!visited[neighbour]) {
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }

            k--;
        }

        return result;
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size(), m = edges2.size();
        vector<vector<int>> graph1(n + 1), graph2(m + 1);
        for (vector<int> edge : edges1) {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }

        for (vector<int> edge : edges2) {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }

        vector<int> dist1;
        for (int i = 0; i <= n; i++) {
            int reachableNodes = bfs(graph1, i, k);
            cout << reachableNodes << ", ";
            dist1.push_back(reachableNodes);
        }

        int maxReachableNodes = INT_MIN;
        for (int i = 0; i <= m; i++) {
            int reachableNodes = bfs(graph2, i, k - 1);
            maxReachableNodes = max(maxReachableNodes, reachableNodes);
        }
        cout << endl << maxReachableNodes;

        for (int &dist : dist1) {
            dist += maxReachableNodes;
        }

        return dist1;
    }
};