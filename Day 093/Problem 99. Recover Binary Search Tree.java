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
    private TreeNode firstNode = null, secondNode = null;
    
    public void recoverTree(TreeNode root) {
        dfs(root);

        int temp = firstNode.val;
        firstNode.val = secondNode.val;
        secondNode.val = temp;
    }

    TreeNode prevNode = new TreeNode(Integer.MIN_VALUE);
    private void dfs(TreeNode root) {
        if (root == null) return;
        
        dfs(root.left);
        if (firstNode == null && root.val <= prevNode.val) {
            firstNode = prevNode;
        }

        if (firstNode != null && root.val <= prevNode.val) {
            secondNode = root;
        }

        prevNode = root;
        dfs(root.right);
    }

}
