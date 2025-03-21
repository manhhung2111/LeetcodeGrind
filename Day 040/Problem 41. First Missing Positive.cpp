class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> mp;
        for(int num : nums) {
            mp[num] = 1;
        }

        int num = 1;
        while (true) {
            if (mp[num] == 0) {
                return num;
            }
            num++;
        }
        
        return -1;
    }
};