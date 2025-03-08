class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj (n);
        for (vector<int> flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, INT_MAX);
        // Store {distFromSource, Node, Stops}
        queue<tuple<int, int, int>> pq;

        dist[src] = 0;
        pq.push({0, src, 0}); 

        int result = INT_MAX;
        while (!pq.empty()) {
            auto [distance, node, stops] = pq.front(); pq.pop();
            if (stops > k) continue;

            for (pair<int, int> edge : adj[node]) {
                int neighbor = edge.first;
                int weight = edge.second;

                if (dist[neighbor] > distance + weight) {
                    dist[neighbor] = distance + weight;
                    pq.push({dist[neighbor], neighbor, stops + 1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};