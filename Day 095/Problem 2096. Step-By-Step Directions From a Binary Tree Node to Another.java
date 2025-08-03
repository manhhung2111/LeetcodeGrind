import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Queue;
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
    private static class Edge {
        int neighbor;
        char direction;
        Edge(int neighbor, char direction) {this.neighbor = neighbor; this.direction = direction;}
    }

    private Map<Integer, List<Edge>> buildGraph(TreeNode root) {
        Map<Integer, List<Edge>> graph = new HashMap<>();
        if (root == null) return graph;

        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            graph.computeIfAbsent(node.val, _ -> new ArrayList<>());

            if (node.left != null) {
                graph.computeIfAbsent(node.left.val, _ -> new ArrayList<>());
                graph.get(node.val).add(new Edge(node.left.val, 'L'));
                graph.get(node.left.val).add(new Edge(node.val, 'U'));
                queue.offer(node.left);
            }

            if (node.right != null) {
                graph.computeIfAbsent(node.right.val, _ -> new ArrayList<>());
                graph.get(node.val).add(new Edge(node.right.val, 'R'));
                graph.get(node.right.val).add(new Edge(node.val, 'U'));
                queue.offer(node.right);
            }
        }

        return graph;
    }

    public String getDirections(TreeNode root, int startValue, int destValue) {
        Map<Integer, List<Edge>> graph = buildGraph(root);
        Set<Integer> visited = new HashSet<>();
        Map<Integer, Edge> parent = new HashMap<>();
        Queue<Integer> queue = new ArrayDeque<>();

        queue.add(startValue);
        visited.add(startValue);

        while (!queue.isEmpty() && !parent.containsKey(destValue)) {
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                int node = queue.poll();
                for (Edge edge : graph.getOrDefault(node, new ArrayList<>())) {
                    if (visited.contains(edge.neighbor)) continue;
                    visited.add(edge.neighbor);
                    parent.put(edge.neighbor, new Edge(node, edge.direction));
                    queue.offer(edge.neighbor);
                }
            }
        }

        StringBuilder result =  new StringBuilder();
        while (destValue != startValue) {
            result.append(parent.get(destValue).direction);
            destValue = parent.get(destValue).neighbor;
        }

        return result.reverse().toString();
    }
}