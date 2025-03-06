class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> tree(n);

        for (int i = 0; i < manager.size(); i++) {
            if (i != headID) {
                tree[manager[i]].push_back(i);
            }
        }

        queue<pair<int, int>> q;
        int time = 0;
        q.push({headID, 0});

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                pair<int, int> manager = q.front(); q.pop();

                int managerId = manager.first;
                int currTime = manager.second;
                time = max(time, informTime[managerId] + currTime);

                for (int employee : tree[managerId]) {
                    q.push({employee, informTime[managerId] + currTime});
                }
            }

        }

        return time;
    }
};