#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; // {time, index}
        vector<int> heights (n , 1);

        for (int i = 0; i < n; i++) {
            pq.push({workerTimes[i], i});
        }

        long long result = 0;
        while (mountainHeight > 0) {
            result = pq.top().first;

            while (pq.top().first <= result) {
                auto [time, index] = pq.top(); pq.pop();
                mountainHeight--;
                heights[index]++;
                time += (long long)workerTimes[index] * (long long)heights[index];
                pq.push({time, index});
            }
        }

        return result;
    }
};