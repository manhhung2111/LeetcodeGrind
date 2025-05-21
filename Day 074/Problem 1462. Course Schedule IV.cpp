class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const vector<int>& pre : prerequisites) {
            graph[pre[0]].push_back(pre[1]);
            ++inDegree[pre[1]];
        }

        // Using vector<vector<bool>> instead of unordered_set for fast lookup
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
        queue<int> q;

        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int course = q.front(); q.pop();
            for (int next : graph[course]) {
                // Transfer all prerequisites of current course to its next
                for (int i = 0; i < numCourses; ++i) {
                    if (isPre[course][i]) {
                        isPre[next][i] = true;
                    }
                }
                isPre[next][course] = true;

                if (--inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        vector<bool> result;
        for (const vector<int>& query : queries) {
            result.push_back(isPre[query[1]][query[0]]);
        }

        return result;
    }
};
