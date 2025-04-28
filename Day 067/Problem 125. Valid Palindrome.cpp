class Solution {
public:
    bool isAlphanumeric(char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < s.size() && !isAlphanumeric(s[left])) {
                left++;
            } 

            while (right >= 0 && !isAlphanumeric(s[right])) {
                right--;
            } 

            if (left < right && tolower(s[left++]) != tolower(s[right--])) {
                return false;
            }
        }

        return true;
    }
};