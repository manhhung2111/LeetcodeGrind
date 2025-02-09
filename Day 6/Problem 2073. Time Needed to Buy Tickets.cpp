class Solution {
    public:
        int timeRequiredToBuy(vector<int>& tickets, int k) {
            queue<int> q;
    
            for (int i = 0; i < tickets.size(); i++) {
                q.push(i);
            }
    
            int time = 0;
            while (!q.empty()) {
                time++;
    
                int index = q.front(); q.pop();
                tickets[index]--;
    
                if (tickets[index] != 0) {
                    q.push(index);
                }
    
                if (index == k && tickets[index] == 0) {
                    break;
                }
            }
    
            return time;
        }
    };