class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, vector<int>> mp;

        int degree = 1;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);

            int n = mp[nums[i]].size();
            degree = max(degree, n);
        }

        int answer = nums.size();

        for (auto entry : mp) {
            if (entry.second.size() == degree) {
                answer = min(answer, entry.second.back() - entry.second[0] + 1);
            }
        }

        return answer;
    }
};