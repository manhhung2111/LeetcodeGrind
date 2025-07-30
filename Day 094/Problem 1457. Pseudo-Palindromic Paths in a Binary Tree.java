import java.util.HashMap;
import java.util.Map;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    private int result = 0;
    private void dfs(TreeNode root, Map<Integer, Integer> countMap) {
        if (root == null) return;
        
        countMap.put(root.val, countMap.getOrDefault(root.val, 0) + 1);
        if (root.left == null && root.right == null) {
            int countOddCandidates = 0;
            for (Integer freq : countMap.values()) {
                if ((freq & 1) == 1) countOddCandidates++;
            }
            
            if (countOddCandidates <= 1) this.result++;
        }
        
        dfs(root.left, countMap);
        dfs(root.right, countMap);
        
        countMap.put(root.val, countMap.get(root.val) - 1);
    }
    
    public int pseudoPalindromicPaths (TreeNode root) {
        dfs(root, new HashMap<>());
        return this.result;
    }
}