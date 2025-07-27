import java.util.HashMap;

class Solution {
    public long countOfSubstrings(String word, int k) {
        // This problem can be reformulated as follow: 
        // exactK = atLeast(word, k) - atLeast(word, k + 1);
        return atLeast(word, k) - atLeast(word, k + 1);
    }

    public long atLeast(String word, int k) {
        // We observe that once the window contains every vowel, if we continue whether the next character is vowel or consonant, the window still valid -> validWindowStartsWithLeft = wordLen - end;

        HashMap<Character, Integer> vowelMap = new HashMap<>();
        int countConsonants = 0;
        long result = 0;

        for (int start = 0, end = 0; end < word.length(); end++) {
            char curLetter = word.charAt(end);

            if (isVowel(curLetter)) {
                vowelMap.put(curLetter, vowelMap.getOrDefault(curLetter, 0) + 1);
            } else {
                countConsonants++;
            }

            while (vowelMap.size() == 5 && countConsonants >= k) {
                result += word.length() - end;

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