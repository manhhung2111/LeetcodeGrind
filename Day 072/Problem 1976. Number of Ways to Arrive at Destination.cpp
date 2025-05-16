class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);
        for (vector<int> road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [currDist, node] = pq.top(); pq.pop();
            if (currDist > dist[node]) continue;

            // Relax
            for (auto& [neighbour, weight] : graph[node]) {
                if (dist[neighbour] > dist[node] + weight) {
                    dist[neighbour] = dist[node] + weight;
                    ways[neighbour] = ways[node];
                    pq.push({dist[neighbour], neighbour});
                } else if (dist[neighbour] == dist[node] + weight) {
                    ways[neighbour] = (ways[neighbour] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};