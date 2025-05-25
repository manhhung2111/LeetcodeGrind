class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> wordCount;

        // Count the frequency of each word
        for (const string& word : words) {
            wordCount[word]++;
        }

        int totalLength = 0;
        bool hasCentralPalindrome = false;

        for (auto& [word, count] : wordCount) {
            string reversed = word;
            reverse(reversed.begin(), reversed.end());

            if (word == reversed) {
                // Palindromic word (e.g., "aa", "bb")
                // Use pairs of them to add to the palindrome
                totalLength += (count / 2) * 4;
                if (count % 2 == 1) {
                    hasCentralPalindrome = true; // One can be placed in the center
                }
            } else if (word < reversed && wordCount.count(reversed)) {
                // Match non-palindromic word with its reverse (e.g., "ab" and "ba")
                int pairs = min(count, wordCount[reversed]);
                totalLength += pairs * 4;
            }
        }

        // If there's an unpaired palindromic word, it can be placed in the middle
        if (hasCentralPalindrome) {
            totalLength += 2;
        }

        return totalLength;
    }
};
