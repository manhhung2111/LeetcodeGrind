class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            graph[edge[0]].push_back({edge[1], 1.0 / succProb[i]});
            graph[edge[1]].push_back({edge[0], 1.0 / succProb[i]});
        }

        vector<double> dist(n, INT_MAX);
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        dist[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [distance, node] = pq.top(); pq.pop();
            cout << "Dist" << distance << "Node" << node << endl;
            if (distance > dist[node]) continue;

            for (pair<int, double> edge : graph[node]) {
                int neighbor = edge.first;
                double prob = edge.second;

                if (dist[neighbor] > dist[node] * prob) {
                    dist[neighbor] = dist[node] * prob;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        return dist[end_node] == INT_MAX ? 0 : 1 / dist[end_node];
    }
};