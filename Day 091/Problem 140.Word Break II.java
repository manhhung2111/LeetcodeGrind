import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    List<String> sentences = new ArrayList<>();

    private void dfs(int index, String s, StringBuilder sentence, Set<String> wordSet) {
        if (index == s.length()) {
            sentences.add(sentence.toString().trim());
            return;
        }

        for (int i = index + 1; i <= s.length(); i++) {
            String substr = s.substring(index, i);
            if (wordSet.contains(substr)) {
                int len = sentence.length();

                sentence.append(substr).append(" ");
                dfs(i, s, sentence, wordSet);
                sentence.setLength(len);
            }
        }
    }

    public List<String> wordBreak(String s, List<String> wordDict) {
        Set<String> wordSet = new HashSet<>(wordDict);
        dfs(0, s, new StringBuilder(), wordSet);
        return sentences;
    }
}