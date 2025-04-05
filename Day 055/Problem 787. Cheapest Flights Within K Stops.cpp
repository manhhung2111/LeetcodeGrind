class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> graph;

        for (vector<int> flight : flights) {
            int source = flight[0], dest = flight[1], cost = flight[2];
            graph[source].push_back({dest, cost});
        }

        queue<tuple<int, int, int>> q; // node, dist, stops
        q.push({src, 0, 0});
        int stop = 0;

        while (!q.empty()) {
            auto [node, cost, stops] = q.front(); q.pop();
            if (stops > k) continue;

            for (pair<int, int> edge : graph[node]) {
                auto [neighbor, edgeCost] = edge;
                if (dist[neighbor] > cost + edgeCost) {
                    dist[neighbor] = cost + edgeCost;
                    q.push({neighbor, dist[neighbor], stops + 1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};