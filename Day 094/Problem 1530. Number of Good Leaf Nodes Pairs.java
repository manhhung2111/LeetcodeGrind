import java.util.ArrayList;
import java.util.List;

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
    public int countPairs(TreeNode root, int distance) {
        dfs(root, distance);
        return result;
    }

    private List<Integer> dfs(TreeNode root, int distance) {
        if (root == null) return new ArrayList<>();
        if (root.left == null && root.right == null) {
            return List.of(1);
        }

        List<Integer> left = dfs(root.left, distance);
        List<Integer> right = dfs(root.right, distance);

        for (int l : left) {
            for (int r : right) {
                if (l + r <= distance) {
                    this.result++;
                }
            }
        }

        List<Integer> list = new ArrayList<>();
        for (int l : left) {
            if (l + 1 < distance) list.add(l + 1);
        }

        for (int r : right) {
            if (r + 1 < distance) list.add(r + 1);
        }

        return list;
    }
}