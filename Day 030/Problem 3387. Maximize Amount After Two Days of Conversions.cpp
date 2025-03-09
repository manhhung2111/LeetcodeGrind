class Solution {
public:
    map<string, vector<pair<string, double>>> constructGraph(vector<vector<string>>& pairs, vector<double>& rates) {
        map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < pairs.size(); i++) {
            string currency1 = pairs[i][0], currency2 = pairs[i][1];
            double conversion = rates[i];
            graph[currency1].push_back({currency2, conversion});
            graph[currency2].push_back({currency1, 1.0 / conversion});
        }

        return graph;
    }

    map<string, double> bfs(string source, double value, map<string, vector<pair<string, double>>> &graph) {
        map<string, bool> visited = {{source, true}};
        map<string, double> result = {{source, value}};

        queue<string> q;
        q.push(source);

        while (!q.empty()) {
            string node = q.front(); q.pop();

            for (pair<string, double> edge : graph[node]) {
                string neighbor = edge.first;
                double conversionRate = edge.second;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    result[neighbor] = result[node] * conversionRate;
                }
            }
        }

        return result;
    }


    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        map<string, double> mp = {{initialCurrency, 1.0}};

        map<string, vector<pair<string, double>>> graph1 = constructGraph(pairs1, rates1);
        map<string, vector<pair<string, double>>> graph2 = constructGraph(pairs2, rates2);
        
        map<string, double> day1 = bfs(initialCurrency, 1.0, graph1);

        double result = 1.0;
        for (auto entry : day1) {
            string currency = entry.first;

            map<string, double> temp = bfs(currency, entry.second, graph2);
            if (temp.find(currency) != temp.end()) {
                result = max(result, temp[initialCurrency]);
            }
        }

        return result;
    }
};