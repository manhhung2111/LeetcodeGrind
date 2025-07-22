import java.util.HashMap;

class Solution {
    public long countOfSubstrings(String word, int k) {
        int n = word.length();

        // Find the next consonant for each index
        int[] nextConsonantIndex = new int[n];
        int nextIndex = n;
        for (int i = n - 1; i >= 0; i--) {
            nextConsonantIndex[i] = nextIndex;
            if (!isVowel(word.charAt(i))) {
                nextIndex = i;
            }
        }

        int start = 0;
        long result = 0;
        HashMap<Character, Integer> vowelMap = new HashMap<>();
        int countConsonants = 0;

        for (int end = 0; end < n; end++) {
            char curLetter = word.charAt(end);

            // Add current letter to the window
            if (isVowel(curLetter)) {
                vowelMap.put(curLetter, vowelMap.getOrDefault(curLetter, 0) + 1);
            } else {
                countConsonants++;
            }

            // If the number of consonants is too large
            while (countConsonants > k) {
                char startLetter = word.charAt(start);
                if (isVowel(startLetter)) {
                    vowelMap.put(startLetter, vowelMap.get(startLetter) - 1);
                    if (vowelMap.get(startLetter) == 0) {
                        vowelMap.remove(startLetter);
                    }
                } else {
                    countConsonants--;
                }

                start++;
            }

            // Keep shrinking the window if the window valid
            while (vowelMap.entrySet().size() == 5 && countConsonants == k) {
                result += nextConsonantIndex[end] - end;
                char startLetter = word.charAt(start);
                if (isVowel(startLetter)) {
                    vowelMap.put(startLetter, vowelMap.get(startLetter) - 1);
                    if (vowelMap.get(startLetter) == 0) {
                        vowelMap.remove(startLetter);
                    }
                } else {
                    countConsonants--;
                }

                start++;
            }
        }

        return result;
    }

    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}