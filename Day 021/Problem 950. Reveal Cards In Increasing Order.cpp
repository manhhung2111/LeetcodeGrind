class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if (deck.size() > 1) sort(deck.begin(), deck.end());

        queue<int> q;
        for (int i = 0; i < deck.size(); i++) {
            q.push(i);
        }

        vector<int> answer (deck.size(), 0);
        int index = 0;

        while (!q.empty() && index < deck.size()) {
            answer[q.front()] = deck[index]; q.pop();
            index++;

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return answer;
    }
};