class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);

        return c == 'a' || c == 'e' || c == 'i' 
                || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < s.size() && !isVowel(s[left])) left++;
            while (right > 0 && !isVowel(s[right])) right--;

            if (left > right) break;
            swap(s[left], s[right]);
            left++; right--;
        }

        return s;
    }
};