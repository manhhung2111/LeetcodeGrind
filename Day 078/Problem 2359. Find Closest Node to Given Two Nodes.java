import java.util.LinkedList;
import java.util.Queue;

class Solution {
    int[] bfs(int[] edges, int startNode) {
        int[] dist = new int[edges.length];
        boolean[] visited = new boolean[edges.length];

        dist[startNode] = 0;
        visited[startNode] = true;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(startNode);

        int steps = 0;
        while (!queue.isEmpty()) {
            int n = queue.size();

            for (int i = 0; i < n; i++) {
                int node = queue.poll();
                dist[node] = steps;

                int neighbour = edges[node];
                if (neighbour != -1 && !visited[neighbour]) {
                    queue.add(neighbour);
                    visited[neighbour] = true;
                }
            }

            steps++;
        }
        return dist;
    }
    
    
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int[] dist1 = bfs(edges, node1);
        int[] dist2 = bfs(edges, node2);

        int minDistance = Integer.MAX_VALUE;
        int index = -1;

        for (int i = 0; i < edges.length; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int distance = Math.max(dist1[i], dist2[i]);
                if (distance < minDistance) {
                    minDistance = distance;
                    index = i;
                }
            }
        }

        return index;
    }
}