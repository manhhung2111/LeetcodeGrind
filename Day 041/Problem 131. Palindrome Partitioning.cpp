class Solution {
public:
    bool isPalindrome(int left, int right, string s) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }

        return true;
    }

    vector<vector<string>> result;
    void dfs(int index, string s, vector<string> partitions) {
        if (index == s.size()) {
            result.push_back(partitions);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(index, i, s)) {
                string partition = s.substr(index, i - index + 1);
                partitions.push_back(partition);

                dfs(i + 1, s, partitions);

                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> partition;
        dfs(0, s, partition);

        return result;
    }
};