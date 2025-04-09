class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Min heap
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype([](const auto &a, const auto &b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        })> pq;


        unordered_map<string, int> mp;
        for (string word : words) {
            mp[word]++;
        }

        for (auto entry : mp) {
            pq.push({entry.second, entry.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};