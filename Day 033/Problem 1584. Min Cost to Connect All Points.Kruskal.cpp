class Solution {
public:
    using edge = tuple<pair<int, int>, pair<int, int>, int>;
    map<pair<int, int>, int> rank;
    map<pair<int, int>, pair<int, int>> parent;

    void makeSet(vector<vector<int>>& points) {
        for (vector<int> point : points) {
            rank[{point[0], point[1]}] = 1;
            parent[{point[0], point[1]}] = {point[0], point[1]};
        }
    }

    pair<int, int> unionFind(pair<int, int> point) {
        if (parent[point] == point) return point;
        parent[point] = unionFind(parent[point]);
        return parent[point];
    }

    void unite(pair<int, int> pointA, pair<int, int> pointB) {
        pointA = unionFind(pointA);
        pointB = unionFind(pointB);

        if (pointA == pointB) return;

        if (rank[pointA] > rank[pointB]) {
            parent[pointA] = pointB;
        } else if (rank[pointA] < rank[pointB]) {
            parent[pointB] = pointA;
        } else {
            parent[pointA] = pointB;
            rank[pointA]++;
        }
    }

    vector<edge> constructEdges(vector<vector<int>>& points) {
        vector<edge> edges;

        for (int i = 0; i < points.size() - 1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                vector<int> pointA = points[i], pointB = points[j];
                int weight = abs(pointA[0] - pointB[0]) + abs(pointA[1] - pointB[1]);
                edges.push_back({{pointA[0], pointA[1]}, {pointB[0], pointB[1]}, weight});
            }
        }

        if (edges.size() > 1) {
            sort(edges.begin(), edges.end(), [](const edge &a, const edge &b){
                return get<2>(a) < get<2>(b);
            });
        }

        return edges;
    }

    int kruskal(vector<vector<int>>& points) {
        int result = 0; makeSet(points);
        vector<edge> edges = constructEdges(points);
        
        for (edge edgeNode : edges) {
            auto[pointA, pointB, weight] = edgeNode;

            if (unionFind(pointA) != unionFind(pointB)) {
                unite(pointA, pointB);
                result += weight;
            }
        }

        return result;
    }


    int minCostConnectPoints(vector<vector<int>>& points) {    
        return kruskal(points);
    }
};