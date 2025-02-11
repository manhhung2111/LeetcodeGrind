class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;

        for (string s : strs) {
            if(s.size() > 1) {
                string sortedString = s;
                sort(sortedString.begin(), sortedString.end());
                mp[sortedString].push_back(s);
            }else{
                mp[s].push_back(s);
            }
        }

        vector<vector<string>> answer;
        for (auto entry : mp) {
            answer.push_back(entry.second);
        }

        return answer;
    }
};