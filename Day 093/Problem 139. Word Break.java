import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {

    Boolean[] dp;
    public boolean solve(int index, String s, Set<String> wordSet) {
        if (index == s.length()) {
            return dp[index] = true;
        }
        
        if (dp[index] != null) {
            return dp[index];
        }

        for (int i = index + 1; i <= s.length(); i++) {
            String substr = s.substring(index, i);
            if (wordSet.contains(substr) && solve(i, s, wordSet)) {
                return dp[index] = true;
            }
        }

        return dp[index] = false;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        dp = new Boolean[s.length() + 1];
        Set<String> wordSet = new HashSet<>(wordDict);
        return solve(0, s, wordSet);
    }
}