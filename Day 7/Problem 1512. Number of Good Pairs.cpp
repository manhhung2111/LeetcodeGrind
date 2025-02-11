class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int answer = 0;
        for (auto x : mp) {
            answer += x.second.size() * (x.second.size() - 1) / 2;
        }

        return answer;
    }
};