class Solution {
    public:
        vector<int> singleNumber(vector<int>& nums) {
            int xorAll = 0;
            for (int num : nums) {
                xorAll = xorAll ^ num;
            }
    
            int setBit = xorAll & -(unsigned int)xorAll;
    
            int a = 0, b = 0;
            for (int num : nums) {
                if (num & setBit) {
                    a = a ^ num;
                } else {
                    b = b ^ num;
                }
            }
    
            return {a, b};
        }
    };