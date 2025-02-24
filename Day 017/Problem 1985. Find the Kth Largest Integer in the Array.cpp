class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        map<int, vector<string>> mp;

        for (string num : nums) {
            mp[num.size()].push_back(num);
        }

        for (auto &entry : mp) {
            if (entry.second.size() > 1) sort(entry.second.begin(), entry.second.end());
        }


        auto it = mp.rbegin();
        while (it != mp.rend()) {
            for (int i = it->second.size() - 1; i >= 0; i--) {
                if (k == 1) {
                    return it->second[i];
                }
                k--;
            }
            it++;
        }

        return "";
    }
};