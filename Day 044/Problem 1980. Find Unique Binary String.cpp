class Solution {
public:

    string result = "";
    void solve(int n, string &word, map<string, bool> &mp) {
        if (word.size() == n && mp[word] == false) {
            result = word;
            return;
        }

        if (word.size() >= n) {
            return;
        }

        word.push_back('0');
        solve(n, word, mp);
        word.pop_back();

        word.push_back('1');
        solve(n, word, mp);
        word.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {
        string word = "";
        map<string, bool> mp;
        for (string num : nums) {
            mp[num] = true;
        }
        solve(nums[0].size(), word, mp);
        
        return result;
    }
};