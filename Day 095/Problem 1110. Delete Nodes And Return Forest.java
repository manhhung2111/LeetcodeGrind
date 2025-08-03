import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

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
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        Set<Integer> toDeleteSet = new HashSet<>();
        for (int node : to_delete) toDeleteSet.add(node);

        List<TreeNode> forest = new ArrayList<>();
        root = dfs(root, toDeleteSet, forest);

        if (root != null) {
            forest.add(root);
        }

        return forest;
    }

    private TreeNode dfs(TreeNode root, Set<Integer> toDeleteSet, List<TreeNode> forest) {
        if (root == null) return null;
        
        root.left = dfs(root.left, toDeleteSet, forest);
        root.right = dfs(root.right, toDeleteSet, forest);

        if (toDeleteSet.contains(root.val)) {
            if (root.left != null) forest.add(root.left);
            if (root.right != null) forest.add(root.right);

            return null;
        }

        return root;
    }
}