class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        map<string, bool> isDeadend;
        for (string deadend : deadends) {
            isDeadend[deadend] = true;
        }

        if (isDeadend["0000"]) return -1;
        if (target == "0000") return 0;

        queue<string> q;
        q.push("0000");
        set<string> visited;
        visited.insert("0000");

        int step = 0;
        while (!q.empty()) {
            int n = q.size();
    
            for (int i = 0; i < n; i++) {
                string s = q.front(); q.pop();
                if (s == target) return step;

                for (int j = 0; j < s.size(); j++) {
                    string temp = s;
                    int digit = s[j] - '0';

                    int num1 = (digit + 1) % 10;
                    int num2 = (digit - 1 + 10) % 10;

                    temp[j] = num1 + '0';
                    if (visited.find(temp) == visited.end() && !isDeadend[temp]) {
                        q.push(temp);
                        visited.insert(temp);
                    }

                    temp[j] = num2 + '0';
                    if (visited.find(temp) == visited.end() && !isDeadend[temp]) {
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
            }

            step++;
        }

        return -1;
    }
};