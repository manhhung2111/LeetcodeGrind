class Solution {
private:
    using point = pair<int, int>;
    map<point, point> parent;
    map<point, int> rank;

    bool comparePoints(point a, point b) {
        return a.first == b.first && a.second == b.second;
    }

    point findDSU(point a) {
        if (comparePoints(a, parent[a])) {
            return a;
        }

        return parent[a] = findDSU(parent[a]);
    }

    void uniteDSU(point a, point b) {
        a = parent[a];
        b = parent[b];

        if (comparePoints(a, b)) {
            return;
        }

        if (rank[a] > rank[b]) {
            parent[b] = a;
        } else if (rank[a] < rank[b]) {
            parent[a] = b;
        } else {
            parent[b] = a;
            rank[a]++;
        }
    }
public:
    int distance(point a, point b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        for (vector<int> point : points) {
            parent[{point[0], point[1]}] = {point[0], point[1]};
            rank[{point[0], point[1]}] = 1;
        }

        vector<tuple<point, point, int>> edges;
        for (int i  = 0; i < points.size() - 1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                point a = {points[i][0], points[i][1]};
                point b = {points[j][0], points[j][1]};
                edges.push_back({a, b, distance(a, b)});
            }
        } 

        sort(edges.begin(), edges.end(), [](const auto a, const auto b){
            return get<2>(a) < get<2>(b);
        });

        int minCost = 0;
        for (auto edge : edges) {
            auto [pointA, pointB, dist] = edge;
            if (findDSU(pointA) != findDSU(pointB)) {
                uniteDSU(pointA, pointB);
                minCost += dist;
            }
        }


        return minCost;
    }
};