import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Queue;
import java.util.Set;

class Solution {
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        HashMap<Integer, List<Integer>> graph = new HashMap<>();
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph.putIfAbsent(u, new ArrayList<>());
            graph.putIfAbsent(v, new ArrayList<>());

            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        // Construct parent map -> since the graph can be constructed as a tree with the root val = 0
        Queue<Integer> queue = new ArrayDeque<>();
        HashMap<Integer, Integer> parentMap = new HashMap<>();
        parentMap.put(0, -1);
        queue.offer(0);

        while (!queue.isEmpty()) {
            int node = queue.poll();

            for (int neighbor : graph.get(node)) {
                if (parentMap.containsKey(neighbor)) continue;
                parentMap.put(neighbor, node);
                queue.offer(neighbor);
            }
        }

        Set<String> paths = new HashSet<>();
        for (int i = 0; i < hasApple.size(); i++) {
            if (!hasApple.get(i)) continue;
            while (parentMap.get(i) != -1) {
                int parent = parentMap.get(i);
                paths.add(new StringBuilder().append(parent).append(",").append(i).toString());
                i = parent;
            }  
        }

        return paths.size() * 2;
    }
}