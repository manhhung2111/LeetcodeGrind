class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<int, 3>> indexedTasks;

        for (int i = 0; i < n; ++i) {
            indexedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        // Sort by enqueue time
        sort(indexedTasks.begin(), indexedTasks.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // {processingTime, index}
        vector<int> result;
        long long time = 0;
        int i = 0;

        while (i < n || !pq.empty()) {
            // If no task is available, jump to the next enqueue time
            if (pq.empty() && time < indexedTasks[i][0]) {
                time = indexedTasks[i][0];
            }

            // Add all tasks that have arrived by 'time' to the heap
            while (i < n && indexedTasks[i][0] <= time) {
                pq.push({indexedTasks[i][1], indexedTasks[i][2]});
                ++i;
            }

            if (!pq.empty()) {
                auto [duration, idx] = pq.top(); pq.pop();
                time += duration;
                result.push_back(idx);
            }
        }

        return result;
    }
};
