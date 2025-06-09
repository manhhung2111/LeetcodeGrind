class Solution {
private:
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;
    unordered_map<string, string> emailNameMap;

    string findDSU(const string& email) {
        if (parent.find(email) == parent.end())
            parent[email] = email;
        if (parent[email] != email)
            parent[email] = findDSU(parent[email]);
        return parent[email];
    }

    void uniteDSU(const string& email1, const string& email2) {
        string root1 = findDSU(email1);
        string root2 = findDSU(email2);
        if (root1 == root2) return;

        if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        } else if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Initialize email name map and parent
        for (const auto& account : accounts) {
            const string& name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                const string& email = account[i];
                emailNameMap[email] = name;
                parent[email] = email;  // Ensures all emails are initialized
            }
        }

        // Union emails in the same account
        for (const auto& account : accounts) {
            for (int i = 2; i < account.size(); ++i) {
                uniteDSU(account[i - 1], account[i]);
            }
        }

        // Group emails by root
        unordered_map<string, set<string>> groups;
        for (const auto& [email, _] : emailNameMap) {
            string root = findDSU(email);
            groups[root].insert(email);
        }

        // Build result
        vector<vector<string>> result;
        for (const auto& [root, emails] : groups) {
            vector<string> merged{emailNameMap[root]};
            merged.insert(merged.end(), emails.begin(), emails.end());
            result.push_back(move(merged));
        }

        return result;
    }
};
