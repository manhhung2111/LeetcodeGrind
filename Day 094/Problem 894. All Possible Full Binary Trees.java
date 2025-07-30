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
    Map<Integer, List<TreeNode>> dp = new HashMap<>();
    public List<TreeNode> allPossibleFBT(int n) {
        // A full binary tree must have odd number of nodes
        if ((n & 1) == 0) return new ArrayList<>();
        if (n == 1) return List.of(new TreeNode(0));

        if (dp.containsKey(n)) {
            return dp.get(n);
        }

        List<TreeNode> result = new ArrayList<>();
        for (int i = 1; i < n; i += 2) {
            List<TreeNode> leftNodes = allPossibleFBT(i);
            List<TreeNode> rightNodes = allPossibleFBT(n - 1 - i);

            for (TreeNode leftNode : leftNodes) {
                for (TreeNode rightNode : rightNodes) {
                    result.add(new TreeNode(0, leftNode, rightNode));
                }
            }
        }

        dp.put(n, result);
        return result;
    }
}