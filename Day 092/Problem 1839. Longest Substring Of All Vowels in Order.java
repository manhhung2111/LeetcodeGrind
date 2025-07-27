import java.util.HashSet;
import java.util.Set;

class Solution {
    public int longestBeautifulSubstring(String word) {
        int result = 0;
        Set<Character> seen = new HashSet<>();

        for (int left = 0, right = 0; right < word.length(); right++) {
            if (right > 0 && word.charAt(right - 1) > word.charAt(right)) {
                left = right;
                seen = new HashSet<>();
            }

            seen.add(word.charAt(right));
            if (seen.size() == 5) {
                result = Math.max(result, right - left + 1);
            }
        }

        return result;
    }
}