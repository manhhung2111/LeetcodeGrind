class Solution {
public:
    bool isPalindrome(string str) {
        int left = 0, right = str.size() - 1;

        while (left < right) {
            if (str[left++] != str[right--]) return false;
        }

        return true;
    }

    
    vector<vector<string>> result;
    void solve(int index, const string &s, vector<string> &partitions) {
        if (index == s.size()) {
            result.push_back(partitions);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            string str = s.substr(index, i - index + 1);
            if (isPalindrome(str)) {
                partitions.push_back(str);
                solve(i + 1, s, partitions);
                partitions.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        solve(0, s, partitions);

        return result;
    }
};