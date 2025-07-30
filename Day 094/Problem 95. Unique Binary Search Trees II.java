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
    private List<TreeNode> solve(int left, int right, int[] nums) {
        if (left > right) return new ArrayList<>();
        if (left == right) return List.of(new TreeNode(nums[left]));
        
        List<TreeNode> result = new ArrayList<>();
        for (int i = left; i <= right; i++) {
            List<TreeNode> leftNodes = solve(left, i - 1, nums);
            List<TreeNode> rightNodes = solve(i + 1, right, nums);

            if (leftNodes.isEmpty()) leftNodes.add(null);
            if (rightNodes.isEmpty()) rightNodes.add(null);

            for (TreeNode leftNode : leftNodes) {
                for (TreeNode rightNode : rightNodes) {
                    TreeNode root = new TreeNode(nums[i]);
                    root.left = leftNode;
                    root.right = rightNode;

                    result.add(root);
                } 
            }
        }

        return result;
    }


    public List<TreeNode> generateTrees(int n) {
        int[] nums = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            nums[i] = i;
        }
        return solve(1, n, nums);
    }
}