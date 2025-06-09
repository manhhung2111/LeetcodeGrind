class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](auto &trip1, auto &trip2) {
            return trip1[1] < trip2[1];
        });

        int currCap = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (int i = 0; i < trips.size(); i++) {
            while (!pq.empty() && trips[i][1] >= pq.top().first) {
                auto [endTime, passengers] = pq.top(); pq.pop();
                currCap -= passengers;
            }

            pq.push({trips[i][2], trips[i][0]});
            currCap += trips[i][0];
            if (currCap > capacity) {
                return false;
            }
        }

        return true;
    }
};