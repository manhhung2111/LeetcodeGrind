class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> countMap;
        for (char task : tasks) {
            countMap[task]++;
        }

        priority_queue<pair<int, char>> maxHeap; // freq, task
        for (auto entry : countMap) {
            maxHeap.push({entry.second, entry.first});
        }

        int result = 0;
        while (!maxHeap.empty()) {
            vector<pair<int, char>> remainingTasks;
            int processedTasks = 0;
            for (int i = 0; i <= n; i++) {
                if (!maxHeap.empty()) {
                    auto [count, task] = maxHeap.top(); maxHeap.pop();
                    processedTasks++;
                    if (--count > 0) {
                        remainingTasks.push_back({count, task});
                    }
                }
                
            }
            
            if (remainingTasks.empty()) {
                result += processedTasks;
            } else {
                result += n + 1;
                for (auto entry : remainingTasks) {
                    maxHeap.push(entry);
                }
            }
        }

        return result;
    }
};