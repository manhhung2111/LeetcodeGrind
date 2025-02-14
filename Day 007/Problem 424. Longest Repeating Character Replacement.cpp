class Solution {
public:
    char findDominantCharacter(map<char, int> frequency) {
        char answer = 'a';
        int maxFreq = 0;

        for (auto entry : frequency) {
            if (entry.second > maxFreq) {
                answer = entry.first;
                maxFreq = entry.second;
            }
        }

        return answer;
    }
    
    int characterReplacement(string s, int k) {
        map<char, int> frequency;

        char dominantChar = s[0];
        int windowStart = 0;
        int answer = 0;

        for (int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            frequency[s[windowEnd]]++;

            dominantChar = frequency[dominantChar] > frequency[s[windowEnd]] ? dominantChar : s[windowEnd];
            while (windowEnd - windowStart + 1 - k > frequency[dominantChar]) {
                frequency[s[windowStart]]--;
                windowStart++;
                dominantChar = findDominantCharacter(frequency);
            }

            answer = max(answer, windowEnd - windowStart + 1);
        }

        return answer;
    }
};