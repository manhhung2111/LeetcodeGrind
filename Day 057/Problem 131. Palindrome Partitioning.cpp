class Solution {
public:
    vector<vector<string>> result;
    
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }

        return true;
    }
    
    void solve(int index, vector<string>& partitions, string s) {
        if (index == s.size()) {
            result.push_back(partitions);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            string partition = s.substr(index, i - index + 1);
            if (isPalindrome(partition)) {
                partitions.push_back(partition);
                solve(i + 1, partitions, s);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        solve(0, partitions, s);

        return result;
    }
};