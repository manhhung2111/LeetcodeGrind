class Solution {
public:

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        // Construct graph        
        vector<vector<int>> graph(n);
        vector<int> indegree(n);

        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<array<int, 26>> count(n, array<int, 26>{0});
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                count[i][colors[i] - 'a'] = 1;
            }
        }

        int visited = 0;
        int result = 1;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            visited++;

            result = max(result, count[node][colors[node] - 'a']);

            for (int neighbour : graph[node]) {
                for (int i = 0; i < 26; i++) {
                    count[neighbour][i] = max(count[neighbour][i], count[node][i] + (i == (colors[neighbour] - 'a')));
                }

                if (--indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return visited == n ? result : -1;
    }
};