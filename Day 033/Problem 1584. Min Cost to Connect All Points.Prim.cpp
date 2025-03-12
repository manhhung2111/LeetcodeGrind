class Solution {
public:
    using point = pair<int, int>;

    int minCostConnectPoints(vector<vector<int>>& points) {    
        map<point, vector<pair<point, int>>> graph;
        
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                point pointA = {points[i][0], points[i][1]};
                point pointB = {points[j][0], points[j][1]};
                int weight = abs(pointA.first - pointB.first) + abs(pointA.second - pointB.second);

                graph[pointA].push_back({pointB, weight});
                graph[pointB].push_back({pointA, weight}); // Since it's an undirected graph
            }
        }

        point source = {points[0][0], points[0][1]};
        
        // Min-heap (priority queue) to pick the smallest edge
        priority_queue<pair<int, point>, vector<pair<int, point>>, greater<>> pq;
        pq.push({0, source});

        map<point, bool> inMST;
        int result = 0;
        int edgesUsed = 0;

        while (!pq.empty() && edgesUsed < points.size()) {
            auto [weight, node] = pq.top();
            pq.pop();

            if (inMST[node]) continue;

            inMST[node] = true;
            result += weight;
            edgesUsed++;

            for (auto& [neighbor, edgeWeight] : graph[node]) {
                if (!inMST[neighbor]) {
                    pq.push({edgeWeight, neighbor});
                }
            }
        }

        return result;
    }
};