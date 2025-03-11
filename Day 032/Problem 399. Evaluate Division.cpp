class Solution {
public:

    double bfs(string start, string dest, map<string, vector<pair<string, double>>> &graph) {
        if (graph.find(start) == graph.end()) return -1.0;
        if (start == dest) return 1.0;

        queue<pair<string, double>> q;
        set<string> visited;
        q.push({start, 1.0});
        visited.insert(start);

        double result = -1;
        while(!q.empty()) {
            auto [node, value] = q.front(); q.pop();

            for (pair<string, double> edge : graph[node]) {
                string neighbor = edge.first;
                double weight = edge.second;

                if (visited.find(neighbor) == visited.end()) {
                    q.push({neighbor, value * weight});
                    visited.insert(neighbor);
                    if (neighbor == dest) {
                        return value * weight;
                    }
                }
            }
        }

        return result;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string num1 = equations[i][0], num2 = equations[i][1];
            graph[num1].push_back({num2, values[i]});
            graph[num2].push_back({num1, 1 / values[i]});
        }

        vector<double> result;
        for (vector<string> query : queries) {
            string source = query[0], dest = query[1];
            result.push_back(bfs(source, dest, graph));
        }

        return result;
    }
};