class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;

        map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        for (auto entry : freq) {
            pq.push({entry.second, entry.first});
        }

        string answer = "";

        while (!pq.empty()) {
            pair<int, char> firstPair = pq.top(); pq.pop();
            answer += firstPair.second;

            int freq1 = firstPair.first - 1;

            if (freq1 > 0 && pq.empty()) return "";
            if (!pq.empty()) {
                pair<int, char> secondPair = pq.top(); pq.pop();
                answer += secondPair.second;
                int freq2 = secondPair.first - 1;

                if (freq1 > 0) pq.push({freq1, firstPair.second});
                if (freq2 > 0) pq.push({freq2, secondPair.second});
            }
        }

        return answer;
    }
};