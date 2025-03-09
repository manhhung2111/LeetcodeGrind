class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph (n, vector<int>(n, INT_MAX));
        for(vector<int> edge : edges) {
            int source = edge[0], dest = edge[1], weight = edge[2];
            graph[source][dest] = weight;
            graph[dest][source] = weight;
        }

        for (int i = 0; i < n; i++) {
            graph[i][i] = 0;
        }

        for (int node = 0; node < n; node++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (graph[i][node] == INT_MAX || graph[node][j] == INT_MAX) {
                        continue;
                    } else if (graph[i][j] > graph[i][node] + graph[node][j]) {
                        graph[i][j] = graph[i][node] + graph[node][j];
                    }
                }
            }
        }

        int result = n, answer = 0;
        for (int source = 0; source < n; source++) {
            int count = 0;
            for (int dest = 0; dest < n; dest++) {
                if (graph[source][dest] <= distanceThreshold) count++;
            }

            if (count <= result) {
                answer = source;
                result = count;
            }
        }

        return answer;
    }
};