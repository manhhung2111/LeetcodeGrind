class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto entry : freq) {
            pq.push({entry.second, entry.first});
        }

        string answer = "";
        while (pq.size() > 1) {
            pair<int, char> firstPair = pq.top(); pq.pop();
            answer.push_back(firstPair.second);
            
            if (!pq.empty()) {
                pair<int, char> secondPair = pq.top(); pq.pop();
                answer.push_back(secondPair.second);

                if (secondPair.first - 1 > 0) {
                    pq.push({secondPair.first - 1, secondPair.second});
                }
            }
            
            if (firstPair.first - 1 > 0) {
                pq.push({firstPair.first - 1, firstPair.second});
            }
        }

        if (!pq.empty()) {
            pair<int, char> temp = pq.top();
            if ((answer.size() > 0 && temp.second == answer.back()) || temp.first > 1) {
                return "";
            }
            answer.push_back(temp.second);
        }

        return answer;
    }
};