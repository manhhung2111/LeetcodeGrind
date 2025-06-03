#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // Sort tasks based on enqueue time 
        
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> sortedTasks; // enqueue time, processing time, index
        for (int i = 0; i < tasks.size(); i++) {
            sortedTasks.push({tasks[i][0], tasks[i][1], i});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> availableTasks; // processing time, index
        
        array<int, 3> firstTask = sortedTasks.top(); sortedTasks.pop();
        availableTasks.push({firstTask[1], firstTask[2]});
        long currentTime = firstTask[0];

        vector<int> result;
        while (!availableTasks.empty()) {
            auto [processingTime, index] = availableTasks.top(); availableTasks.pop();
            result.push_back(index);
            currentTime += processingTime;

            while (!sortedTasks.empty() && sortedTasks.top()[0] <= currentTime) {
                auto task = sortedTasks.top(); sortedTasks.pop();
                availableTasks.push({task[1], task[2]});
            }

            if (!sortedTasks.empty() && availableTasks.empty()) {
                auto task = sortedTasks.top(); sortedTasks.pop();
                availableTasks.push({task[1], task[2]});
                currentTime = task[0];
            }
        }

        return result;
    }
};