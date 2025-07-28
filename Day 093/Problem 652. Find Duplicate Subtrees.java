import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
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
    
    Map<TreeNode, String> treeMap = new HashMap<>();
    List<TreeNode> result = new ArrayList<>();
    Map<String, Integer> seen = new HashMap<>();

    private String dfs(TreeNode root) {
        if (root == null) return "";
        if(treeMap.containsKey(root)) return treeMap.get(root);

        String str = new StringBuilder().append(root.val).append('#').append(dfs(root.left)).append('#').append(dfs(root.right)).toString();    
        if (seen.getOrDefault(str, 0) == 1) {
            result.add(root);
        }
        seen.put(str, seen.getOrDefault(str, 0) + 1);

        return str;
    }

    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        dfs(root);
        return result;
    }
}