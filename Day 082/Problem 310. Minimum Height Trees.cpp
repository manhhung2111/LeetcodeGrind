class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for (vector<int> edge : edges) {
            indegree[edge[0]]++;
            indegree[edge[1]]++;

            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                leaves.push_back(i);
            }
        }

        while (n > 2) {
            vector<int> newLeaves;
            n -= leaves.size();
            for (int leave : leaves) {
                for (int neighbour : graph[leave]) {
                    indegree[neighbour]--;
                    if (indegree[neighbour] == 1) {
                        newLeaves.push_back(neighbour);
                    }
                }
            }

            leaves = move(newLeaves);
        }
        
        return leaves;
    }
};