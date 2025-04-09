class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int num : nums) {
            mp[num]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for(auto entry : mp) {
            pq.push({entry.second, entry.first});
        }
        vector<int> answer;
        while(answer.size() < k) {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }
};