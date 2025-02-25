class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.size() - 1;

        int deletedChars = 0;
        while (left < right && s[left] == s[right]) {
            if (s[left] != s[right]) break;

            while (left < right && s[left] == s[left+1]) left++;
            while (right > left && s[right] == s[right-1]) right--;

            if (s[left] == s[right]) {
                left++; right--;
            }
        }

        return left <= right ? right - left + 1 : 0;
    }
};