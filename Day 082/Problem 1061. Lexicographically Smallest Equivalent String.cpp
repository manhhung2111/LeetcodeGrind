class Solution {
private:
    vector<int> parent;
    vector<int> rank;

    void initializeDSU(int n) {
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int findDSU(int a) {
        if (parent[a] == a) return a;
        return parent[a] = findDSU(parent[a]);
    }

    void uniteDSU(int a, int b) {
        a = findDSU(a);
        b = findDSU(b);

        if (a == b) return;

        if (rank[a] > rank[b]) {
            parent[b] = a;
        } else if (rank[b] > rank[a]) {
            parent[a] = b;
        } else {
            parent[b] = a;
            rank[a]++;
        }
    }
public:
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        initializeDSU(26);

        for (int i = 0; i < s1.size(); i++) {
            uniteDSU(s1[i] - 'a', s2[i] - 'a');
        }

        // Find smallest character for each character
        unordered_map<int, int> mp;
        for (int i = 0; i < 26; i++) {
            mp[i] = i;
            for (int j = 0; j < 26; j++) {
                if (findDSU(i) == findDSU(j) && j < i) {
                    mp[i] = j;
                    break;
                }
            }
        }

        string result = "";
        for (int i = 0; i < baseStr.size(); i++) {
            char c = mp[baseStr[i] - 'a'] + 'a';
            result.push_back(c);
        }

        return result;
    }
};