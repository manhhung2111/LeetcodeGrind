class Solution {
public:    

    int numberOfSubstrings(string s) {
        array<int, 3> count = {0, 0, 0};
        int left = 0;

        int result = 0;
        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'a']++;
            
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                count[s[left] - 'a']--;
                left++;
            }

            result += (right + 1) - (right - left + 1);
        }

        return result;     
    }
};