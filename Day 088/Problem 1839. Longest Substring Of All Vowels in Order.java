import java.util.HashSet;
import java.util.Set;

class Solution {
    public int longestBeautifulSubstring(String word) {
        int longest = 0;
        Set<Character> seen = new HashSet<>();

        int start = 0;
        for (int end = 0; end < word.length(); ++end) {
            if (end > 0 && word.charAt(end - 1) > word.charAt(end)) {
                seen = new HashSet<>();
                start = end;
            }
            seen.add(word.charAt(end));
            if (seen.size() == 5) {
                longest = Math.max(longest, end - start + 1);
            }
        }
        return longest;
    }
}