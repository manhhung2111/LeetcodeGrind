class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string result = "";
        while (!pq.empty()) {
            auto [freq1, letter1] = pq.top(); pq.pop();
            if (result.size() > 1 && letter1 == result.back() && letter1 == result[result.size() - 2]) {
                if (pq.empty()) {
                    break;
                }

                auto [freq2, letter2] = pq.top(); pq.pop();
                result.push_back(letter2);
                if (--freq2 > 0) {
                    pq.push({freq2, letter2});
                }
            } else {
                result.push_back(letter1);
                freq1--;
            }

            if (freq1 > 0) {
                pq.push({freq1, letter1});
            }
        }

        return result;
    }
};