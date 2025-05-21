class Solution {
private:
    vector<int> helper(int k, vector<vector<int>> &conditions) {
        vector<vector<int>> adj(k + 1);
        vector<int> indegree(k + 1, 0);

        for (vector<int> condition : conditions) {
            adj[condition[0]].push_back(condition[1]);
            indegree[condition[1]]++;
        }

        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            result.push_back(node);

            for (int neighbour : adj[node]) {
                if (--indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        if (result.size() != k) return {};
        return result;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowsOrder = helper(k, rowConditions);
        vector<int> colsOrder = helper(k, colConditions);


        if (rowsOrder.empty() || colsOrder.empty()) return {};
        vector<vector<int>> result (k, vector<int>(k, 0));

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (rowsOrder[i] == colsOrder[j]) {
                    result[i][j] = rowsOrder[i];
                }
            }
        }

        return result;
    }
};