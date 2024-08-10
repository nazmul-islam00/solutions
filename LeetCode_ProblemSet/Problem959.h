#include <vector>
#include <string>
#include <queue>
#include <functional>


class Solution {
public:
    int regionsBySlashes(std::vector<std::string>& grid) {
        auto graph = this->generateGraph(grid);
        return this->getRegionCount(graph);
    }

    std::vector<std::vector<int>> generateGraph(std::vector<std::string>& grid) {
        int rows = grid.size() * 3, cols = grid.size() * 3;
        std::vector<std::vector<int>> graph(rows, std::vector<int> (cols, 0));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] == '\\') {
                    graph[3 * i][3 * j] = graph[3 * i + 1][3 * j + 1] = graph[3 * i + 2][3 * j + 2] = 1;
                } else if (grid[i][j] == '/') {
                    graph[3 * i][3 * j + 2] = graph[3 * i + 1][3 * j + 1] = graph[3 * i + 2][3 * j] = 1;
                }
            }
        }

        return graph;
    }

    int getRegionCount(std::vector<std::vector<int>>& graph) {
        int regionCount = 0;

        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.size(); j++) {
                if (graph[i][j] == 0) {
                    this->bfs(graph, i, j);
                    regionCount++;
                }
            }
        }

        return regionCount;
    }

    void bfs(std::vector<std::vector<int>>& graph, int srcX, int srcY) {
        std::queue<std::pair<int, int>> q;
        q.push({srcX, srcY});
        graph[srcX][srcY] = 1;
        std::vector<int> changeX = {-1, 0, 0, 1};
        std::vector<int> changeY = {0, -1, 1, 0};

        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            int x = cell.first, y = cell.second;
            for (int i = 0; i < 4; i++) {
                int neighborX = x + changeX[i], neighborY = y + changeY[i];
                if (0 <= neighborX && neighborX < graph.size() &&
                    0 <= neighborY && neighborY < graph.size() &&
                    graph[neighborX][neighborY] == 0) {
                        graph[neighborX][neighborY] = 1;
                        q.push({neighborX, neighborY});
                }
            }
        }
    }
};