class Solution {
public:
    vector<string> generate(string password) {
        vector<string> result;
        for (int i = 0; i < password.size(); i++) {
            int val = password[i] - '0';
            string temp = password;

            temp[i] = (val + 1 + 10) % 10 + '0';
            result.push_back(temp);

            temp[i] = (val - 1 + 10) % 10 + '0';
            result.push_back(temp);
        }

        return result;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead (deadends.begin(), deadends.end());
        unordered_set<string> visited = {"0000"};
        
        if (dead.find("0000") != dead.end()) return -1;

        queue<string> q;
        q.push("0000");

        int count = 0;
        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                string password = q.front(); q.pop();

                if (password == target) {
                    return count;
                }

                for (string neighbor : generate(password)) {
                    if (dead.find(neighbor) == dead.end() && visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }

            count++;
        }

        return -1;
    }
};