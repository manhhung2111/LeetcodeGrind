class Solution {
    public:
        vector<int> deckRevealedIncreasing(vector<int>& deck) {
            if (deck.size() == 1) return deck;
            sort(deck.begin(), deck.end());
    
            queue<int> q;
            for (int i = 0; i < deck.size(); i++) {
                q.push(i);
            }
    
            int index = 0;
            vector<int> answer (deck.size(), 0);
    
            while (!q.empty() && index < deck.size()) {
                int firstIndex = q.front(); q.pop();
                answer[firstIndex] = deck[index];
                index++;
                if (!q.empty()) {
                    int secondIndex = q.front(); q.pop();
                    q.push(secondIndex);
                }
            }
    
            return answer;
        }
    };