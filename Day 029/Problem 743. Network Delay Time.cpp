class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (vector<int> time : times) {
            int source = time[0], dest = time[1], weight = time[2];
            adj[source].push_back({dest, weight});
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            pair<int, int> entry = pq.top(); pq.pop();
            int node = entry.second;
            int distance = entry.first;

            if (distance > dist[node]) continue;

            // Relaxation
            for (pair<int, int> edge : adj[node]) {
                int dest = edge.first;
                int weight = edge.second;

                if (dist[dest] > dist[node] + weight) {
                    dist[dest] = dist[node] + weight;
                    pq.push({dist[dest], dest});
                }
            }
        }

        int result = 0;
        for (int i = 1; i <= n; i++) {
            result = max(result, dist[i]);
        }

        return result == INT_MAX ? -1 : result;
    }
};