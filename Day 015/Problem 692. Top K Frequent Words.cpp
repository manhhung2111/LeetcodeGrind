class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        if (words.size() > 1) sort(words.begin(), words.end());

        map<string, int> freq;
        for (string word : words) {
            freq[word]++;
        }


       auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) return a.second > b.second; // Sort lexicographically if freq is the same
            return a.first < b.first; // Higher frequency comes first
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
        for (auto entry : freq) {
            pq.push({entry.second, entry.first});
        }

        vector<string> answer;
        while (k-- && !pq.empty()) {
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;
    }
};