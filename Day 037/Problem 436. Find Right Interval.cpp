class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) {
            if (intervals[0][0] >= intervals[0][1]) return {0};
            return {-1};
        }
        
        map<vector<int>, int> idx;
        for (int i = 0; i < intervals.size(); i++) {
            idx[intervals[i]] = i;
        }

        vector<vector<int>> temp = intervals;
        sort(temp.begin(), temp.end(), [](const auto &a, const auto &b) {return a[0] < b[0];});
        
        map<vector<int>, int> mp;
        for (int i = 0; i < temp.size(); i++) {
            int target = temp[i][1];
            if (temp[i][0] >= target) {
                mp[temp[i]] = idx[temp[i]];
                continue;
            } 
            
            int low = i, high = temp.size() - 1;
            int index = -1;
            
            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (temp[mid][0] >= target) {
                    index = idx[temp[mid]];
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            mp[temp[i]] = index;
        }

        vector<int> result;
        for (vector<int> interval : intervals) {
            if (mp.find(interval) == mp.end()) {
                result.push_back(-1);
            } else {
                result.push_back(mp[interval]);
            }
        }

        return result;
    }
};