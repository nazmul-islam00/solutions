import java.util.LinkedList;
import java.util.Queue;
import java.util.AbstractMap.SimpleEntry;


class Solution {
    public int regionsBySlashes(String[] grid) {
        var graph = this.generateGraph(grid);
        return this.getRegionCount(graph);
    }

    private int[][] generateGraph(String[] grid) {
        int rows = grid.length * 3, cols = grid.length * 3;
        int[][] graph = new int[rows][cols];

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid.length; j++) {
                if (grid[i].charAt(j) == '/') {
                    graph[3 * i][3 * j + 2] = graph[3 * i + 1][3 * j + 1] = graph[3 * i + 2][3 * j] = 1;
                } else if (grid[i].charAt(j) == '\\') {
                    graph[3 * i][3 * j] = graph[3 *i + 1][3 * j + 1] = graph[3 * i + 2][3 * j + 2] = 1; 
                }
            }
        }

        return graph;
    }

    private int getRegionCount(int[][] graph) {
        int regionCount = 0;

        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph.length; j++) {
                if (graph[i][j] == 0) {
                    this.bfs(graph, i, j);
                    regionCount++;
                }
            }
        }

        return regionCount;
    }

    private void bfs(int[][] graph, int srcX, int srcY) {
        Queue<SimpleEntry<Integer, Integer>> q = new LinkedList<>();
        q.add(new SimpleEntry<>(srcX, srcY));
        graph[srcX][srcY] = 1;
        int[] changeX = {-1, 0, 0, 1};
        int[] changeY = {0, -1, 1, 0};

        while (!q.isEmpty()) {
            var cell = q.remove();
            int x = cell.getKey(), y = cell.getValue();
            for (int i = 0; i < 4; i++) {
                int neighborX = x + changeX[i], neighborY = y + changeY[i];
                if (0 <= neighborX && neighborX < graph.length &&
                    0 <= neighborY && neighborY < graph.length &&
                    graph[neighborX][neighborY] == 0) {
                        graph[neighborX][neighborY] = 1;
                        q.add(new SimpleEntry<>(neighborX, neighborY));
                }
            }
        }
    }
}