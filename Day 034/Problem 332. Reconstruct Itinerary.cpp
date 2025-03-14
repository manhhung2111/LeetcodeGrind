class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> graph;
        for (vector<string> ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        stack<string> stk;
        stk.push("JFK");

        vector<string> result;
        while (!stk.empty()) {
            string node = stk.top();

            if (graph[node].size() == 0) {
                result.push_back(node);
                stk.pop();
            } else {
                auto neighbor = graph[node].begin();
                stk.push(*neighbor);
                graph[node].erase(neighbor);
            }
        }

        if (result.size() > 1) reverse(result.begin(), result.end());

        return result;
    }
};