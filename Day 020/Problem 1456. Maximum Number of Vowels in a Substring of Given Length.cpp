class Solution {
public:
    bool isVowel (char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int count = 0, answer = 0;

        int windowStart = 0, windowEnd = 0;
        while (windowEnd < s.size()) {
            if (isVowel(s[windowEnd])) count++;

            if (windowEnd - windowStart + 1 == k) {
                answer = max(answer, count);

                if (isVowel(s[windowStart])) count--;
                windowStart++;
            }

            windowEnd++;
        }

        return answer;
    }
};