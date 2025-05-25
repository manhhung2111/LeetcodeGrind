class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> availabilityMap, wantMap;
        for (int num : nums) {
            availabilityMap[num]++;
        }

        for (int num : nums) {
            if (availabilityMap[num] <= 0) {
                continue;
            } else if (wantMap[num] > 0) {
                wantMap[num]--;
                availabilityMap[num]--;
                wantMap[num + 1]++;
            } else if (availabilityMap[num] > 0 && availabilityMap[num + 1] > 0 && availabilityMap[num + 2] > 0) {
                availabilityMap[num]--;
                availabilityMap[num + 1]--;
                availabilityMap[num + 2]--;
                wantMap[num + 3]++;
            } else {
                return false;
            }
        }

        return true;
    }
};